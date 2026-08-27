import { readdir, readFile, stat } from 'node:fs/promises';
import path from 'node:path';

async function exists(target) {
  try {
    return await stat(target);
  } catch {
    return null;
  }
}

async function scanTestcases(problemPath, prefix, testcaseEntry) {
  if (!testcaseEntry) return [];
  const root = path.join(problemPath, testcaseEntry.name);
  const sides = {};
  for (const [side, extension] of [['input', '.in'], ['output', '.out']]) {
    const folder = path.join(root, side);
    if (!(await exists(folder))) { sides[side] = new Map(); continue; }
    const entries = (await readdir(folder, { withFileTypes: true })).filter((entry) => entry.isFile() && entry.name.endsWith(extension));
    sides[side] = new Map(await Promise.all(entries.map(async (entry) => {
      const id = entry.name.slice(0, -extension.length);
      const filePath = path.join(folder, entry.name);
      return [id, { path: `${prefix}/${testcaseEntry.name}/${side}/${entry.name}`, size: (await stat(filePath)).size }];
    })));
  }
  const ids = new Set([...sides.input.keys(), ...sides.output.keys()]);
  return [...ids].sort((a, b) => a.localeCompare(b, undefined, { numeric: true })).map((id) => ({
    id,
    input: sides.input.get(id) || null,
    output: sides.output.get(id) || null,
  }));
}

export async function scanProblemLibrary(root) {
  const problems = [];
  const categoryEntries = await readdir(root, { withFileTypes: true });
  for (const categoryEntry of categoryEntries.filter((entry) => entry.isDirectory()).sort((a, b) => a.name.localeCompare(b.name))) {
    const categoryPath = path.join(root, categoryEntry.name);
    const problemEntries = await readdir(categoryPath, { withFileTypes: true });
    for (const problemEntry of problemEntries.filter((entry) => entry.isDirectory()).sort((a, b) => a.name.localeCompare(b.name))) {
      const problemPath = path.join(categoryPath, problemEntry.name);
      const metadataPath = path.join(problemPath, 'metadata.json');
      if (!(await exists(metadataPath))) continue;
      const metadata = JSON.parse(await readFile(metadataPath, 'utf8'));
      const files = await readdir(problemPath, { withFileTypes: true });
      const solutionFile = files.find((entry) => entry.isFile() && entry.name.startsWith('solution.'));
      const pdfFile = files.find((entry) => entry.isFile() && entry.name === 'problem.pdf');
      const testcaseEntry = files.find((entry) => entry.isDirectory() && ['testcase', 'testcases'].includes(entry.name));
      const prefix = `problems/${categoryEntry.name}/${problemEntry.name}`;
      const testcases = await scanTestcases(problemPath, prefix, testcaseEntry);
      problems.push({
        id: `${categoryEntry.name}/${problemEntry.name}`,
        code: metadata.code,
        title: metadata.title,
        category: metadata.category,
        categorySlug: categoryEntry.name,
        categoryOrder: metadata.categoryOrder,
        pdf: pdfFile ? `${prefix}/${pdfFile.name}` : null,
        solution: solutionFile ? `${prefix}/${solutionFile.name}` : null,
        solutionLanguage: solutionFile ? path.extname(solutionFile.name).slice(1) : null,
        testcase: testcaseEntry ? `${prefix}/${testcaseEntry.name}` : null,
        testcases,
      });
    }
  }
  return problems.sort((a, b) => a.categoryOrder - b.categoryOrder || a.code.localeCompare(b.code));
}
