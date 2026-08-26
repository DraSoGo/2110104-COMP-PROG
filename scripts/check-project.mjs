import { readFile, readdir, stat } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createHash } from 'node:crypto';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const source = process.env.CONTENT_SOURCE_DIR || '/home/drasogun/Downloads/drive-download-20260826T055608Z-1-001';
const problems = JSON.parse(await readFile(path.join(root, 'data', 'problems.json'), 'utf8'));
const errors = [];
const ids = new Set();
async function exists(file) { try { return (await stat(file)).isFile() || (await stat(file)).isDirectory(); } catch { return false; } }
async function hash(file) { return createHash('sha256').update(await readFile(file)).digest('hex'); }
async function walk(folder, accept) {
  const files = [];
  for (const entry of await readdir(folder, { withFileTypes: true })) {
    if (['.git', 'dist', 'problems'].includes(entry.name)) continue;
    const target = path.join(folder, entry.name);
    if (entry.isDirectory()) files.push(...await walk(target, accept));
    else if (entry.isFile() && accept(target)) files.push(target);
  }
  return files;
}

const sourceAvailable = await exists(source);

for (const problem of problems) {
  if (ids.has(problem.id)) errors.push(`Duplicate id: ${problem.id}`);
  ids.add(problem.id);
  for (const key of ['pdf', 'solution', 'testcase']) if (problem[key] && !(await exists(path.join(root, problem[key])))) errors.push(`Missing ${key}: ${problem[key]}`);
  if (!problem.code || !problem.title || !problem.category) errors.push(`Incomplete metadata: ${problem.id}`);
  if (problem.pdf && sourceAvailable) {
    const metadata = JSON.parse(await readFile(path.join(root, 'problems', problem.id, 'metadata.json'), 'utf8'));
    const original = path.join(source, metadata.source);
    if (!(await exists(original))) errors.push(`Missing original PDF: ${metadata.source}`);
    else if ((await hash(original)) !== (await hash(path.join(root, problem.pdf)))) errors.push(`PDF differs from original: ${problem.id}`);
  }
}

const expected = { problems: 195, pdfs: 134, solutions: 167, testcases: 0, categories: 19 };
const actual = { problems: problems.length, pdfs: problems.filter((item) => item.pdf).length, solutions: problems.filter((item) => item.solution).length, testcases: problems.filter((item) => item.testcase).length, categories: new Set(problems.map((item) => item.category)).size };
for (const [key, value] of Object.entries(expected)) if (actual[key] !== value) errors.push(`Expected ${value} ${key}, found ${actual[key]}`);
const originalSolutionHashes = (await Promise.all((await walk(root, (file) => file.endsWith('.cpp'))).map(hash))).sort();
const organizedSolutionHashes = (await Promise.all(problems.filter((item) => item.solution).map((item) => hash(path.join(root, item.solution))))).sort();
if (originalSolutionHashes.length && JSON.stringify(originalSolutionHashes) !== JSON.stringify(organizedSolutionHashes)) errors.push('Organized solution copies differ from the complete original solution set.');
if (errors.length) { console.error(errors.join('\n')); process.exitCode = 1; }
else {
  console.log(`Validated ${actual.problems} problems, ${actual.pdfs} PDFs, ${actual.solutions} solutions, ${actual.testcases} testcase sets, and ${actual.categories} categories.`);
  if (!sourceAvailable) console.log('Original PDF source is not present; organized PDF paths and counts were validated.');
  else console.log('Every organized PDF matches its source byte for byte.');
  console.log(originalSolutionHashes.length ? 'Every organized solution matches its source byte for byte.' : 'The original solution tree is not present, so organized solution paths and counts were validated.');
}
