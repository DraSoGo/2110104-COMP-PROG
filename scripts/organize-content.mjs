import { COPYFILE_EXCL } from 'node:constants';
import { copyFile, mkdir, readFile, readdir, stat, writeFile } from 'node:fs/promises';
import { execFileSync } from 'node:child_process';
import { createHash } from 'node:crypto';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { slugify } from '../src/lib/content.js';

const projectRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const pdfSource = path.resolve(process.argv[2] || '/home/drasogun/Downloads/drive-download-20260826T055608Z-1-001');
const libraryRoot = path.join(projectRoot, 'problems');

const topicByPrefix = {
  '00': ['00-introduction', 'Introduction'],
  '01': ['01-expressions-and-strings', 'Expressions & Basic Strings'],
  '02': ['02-conditionals', 'Conditionals'],
  '03': ['03-loops', 'Loops & Iteration'],
  '04': ['04-arrays', 'Arrays & Grids'],
  '05': ['05-strings', 'String Processing'],
  '06': ['06-vectors', 'Vectors & Algorithms'],
  '07': ['07-sets', 'Sets'],
  '08': ['08-maps', 'Maps & Lookup'],
  '09': ['09-recursion', 'Recursion'],
};

const examCategories = {
  'Midterm/2023 Midterm': ['10-midterm-2023', 'Midterm 2023'],
  'Midterm/2024 Midterm': ['11-midterm-2024', 'Midterm 2024'],
  'Midterm/2024 Midterm Mock Exam': ['12-midterm-2024-mock', 'Midterm 2024 Mock Exam'],
  'Final/2023 Final': ['13-final-2023', 'Final 2023'],
  'Final/2024 Final': ['14-final-2024', 'Final 2024'],
  'Final/2024 Final Mock Exam': ['15-final-2024-mock', 'Final 2024 Mock Exam'],
  'Final/2025 Final': ['16-final-2025', 'Final 2025'],
};

const titleOverrides = {
  'Final/2023 Final/2023_Final_01.pdf': 'The Squid Game',
  'Final/2023 Final/2023_Final_02.pdf': 'Certified Students',
  'Final/2023 Final/2023_Final_03.pdf': 'Company Department',
  'Final/2023 Final/2023_Final_04.pdf': 'Volleyball',
};

function humanize(value) {
  return value.trim().replace(/[_-]+/g, ' ').replace(/\s+/g, ' ').replace(/\b\w/g, (letter) => letter.toUpperCase());
}

function pdfTitle(absolutePath, relativePath, code) {
  if (titleOverrides[relativePath]) return titleOverrides[relativePath];
  try {
    const text = execFileSync('pdftotext', ['-f', '1', '-l', '1', '-layout', absolutePath, '-'], { encoding: 'utf8', stdio: ['ignore', 'pipe', 'ignore'] });
    const firstLine = text.split(/\r?\n/).map((line) => line.trim()).find(Boolean);
    if (firstLine) return firstLine.replace(/_/g, ' ');
  } catch {}
  try {
    const info = execFileSync('pdfinfo', [absolutePath], { encoding: 'utf8', stdio: ['ignore', 'pipe', 'ignore'] });
    const raw = info.match(/^Title:\s*(.+)$/m)?.[1]?.trim().replace(/\.(pdf|docx)$/i, '');
    if (raw && !/^Microsoft Word/i.test(raw)) return humanize(raw);
  } catch {}
  return code;
}

async function walk(root, extension) {
  const found = [];
  async function visit(folder) {
    for (const entry of await readdir(folder, { withFileTypes: true })) {
      const target = path.join(folder, entry.name);
      if (entry.isDirectory()) await visit(target);
      else if (entry.isFile() && entry.name.toLowerCase().endsWith(extension)) found.push(target);
    }
  }
  await visit(root);
  return found.sort();
}

async function digest(file) {
  return createHash('sha256').update(await readFile(file)).digest('hex');
}

async function safeCopy(source, destination, conflicts) {
  await mkdir(path.dirname(destination), { recursive: true });
  try {
    await copyFile(source, destination, COPYFILE_EXCL);
    return 'copied';
  } catch (error) {
    if (error.code !== 'EEXIST') throw error;
    if ((await digest(source)) === (await digest(destination))) return 'identical';
    conflicts.push({ source, destination });
    return 'conflict';
  }
}

function pdfDescriptor(file) {
  const relative = path.relative(pdfSource, file).split(path.sep).join('/');
  const directory = path.posix.dirname(relative);
  const code = path.basename(file, path.extname(file));
  if (directory === 'Grader') {
    const prefix = code.slice(0, 2);
    const [categorySlug, category] = topicByPrefix[prefix];
    return { relative, code, categorySlug, category, categoryOrder: Number(prefix) };
  }
  const [categorySlug, category] = examCategories[directory];
  return { relative, code, categorySlug, category, categoryOrder: Number(categorySlug.slice(0, 2)) };
}

function solutionTitleFromFilename(file) {
  const filename = path.basename(file, '.cpp').trim();
  const ovenMatch = filename.match(/^([A-Z]\d{2}-\d{4})_(.+)$/);
  const quizMatch = filename.match(/^(Q\d{2})_(.+)$/);
  if (ovenMatch) return { code: ovenMatch[1], title: humanize(ovenMatch[2]) };
  if (quizMatch) return { code: quizMatch[1], title: humanize(quizMatch[2]) };
  return { code: filename, title: humanize(filename) };
}

async function writeMetadata(folder, metadata, conflicts) {
  const target = path.join(folder, 'metadata.json');
  const content = `${JSON.stringify(metadata, null, 2)}\n`;
  try {
    await writeFile(target, content, { flag: 'wx' });
  } catch (error) {
    if (error.code !== 'EEXIST') throw error;
    if ((await readFile(target, 'utf8')) !== content) conflicts.push({ source: 'generated metadata', destination: target });
  }
}

const conflicts = [];
const records = new Map();
const pdfFiles = await walk(pdfSource, '.pdf');

for (const file of pdfFiles) {
  const descriptor = pdfDescriptor(file);
  const title = pdfTitle(file, descriptor.relative, descriptor.code);
  const folderName = slugify(descriptor.code, title);
  const folder = path.join(libraryRoot, descriptor.categorySlug, folderName);
  const record = { ...descriptor, title, folder };
  records.set(descriptor.code, record);
  await mkdir(folder, { recursive: true });
  await safeCopy(file, path.join(folder, 'problem.pdf'), conflicts);
  await writeMetadata(folder, {
    code: descriptor.code,
    title,
    category: descriptor.category,
    categoryOrder: descriptor.categoryOrder,
    source: descriptor.relative,
  }, conflicts);
}

const cppFiles = (await walk(projectRoot, '.cpp')).filter((file) => !file.startsWith(libraryRoot + path.sep));
for (const file of cppFiles) {
  const relative = path.relative(projectRoot, file).split(path.sep).join('/');
  let record;
  const filenameCode = path.basename(file, '.cpp').trim();
  if (relative.startsWith('Grader/midterm67/')) {
    const problemNumber = filenameCode.match(/P(\d+)$/)?.[1];
    record = records.get(`2024_Midterm_0${problemNumber}`);
  } else if (relative.startsWith('Grader/')) {
    record = records.get(filenameCode);
  }

  if (!record && relative.startsWith('Ovenbreak/Grader/')) {
    const parsed = solutionTitleFromFilename(file);
    const categorySlug = '17-ovenbreak';
    const folder = path.join(libraryRoot, categorySlug, slugify(parsed.code, parsed.title));
    record = { ...parsed, categorySlug, category: 'Ovenbreak', categoryOrder: 17, folder, relative: null };
    records.set(`solution:${relative}`, record);
  }
  if (!record && relative.startsWith('Ovenbreak/Quiz/')) {
    const parsed = solutionTitleFromFilename(file);
    const categorySlug = '18-quizzes';
    const folder = path.join(libraryRoot, categorySlug, slugify(parsed.code, parsed.title));
    record = { ...parsed, categorySlug, category: 'Quizzes', categoryOrder: 18, folder, relative: null };
    records.set(`solution:${relative}`, record);
  }
  if (!record) continue;
  await mkdir(record.folder, { recursive: true });
  await safeCopy(file, path.join(record.folder, 'solution.cpp'), conflicts);
  await writeMetadata(record.folder, {
    code: record.code,
    title: record.title,
    category: record.category,
    categoryOrder: record.categoryOrder,
    ...(record.relative ? { source: record.relative } : {}),
  }, conflicts);
}

if (conflicts.length) {
  console.error(JSON.stringify({ conflicts }, null, 2));
  process.exitCode = 1;
} else {
  console.log(JSON.stringify({ pdfs: pdfFiles.length, solutions: cppFiles.length, problemRecords: records.size, conflicts: 0 }, null, 2));
}
