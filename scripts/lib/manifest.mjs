import { readdir, readFile, stat } from 'node:fs/promises';
import path from 'node:path';

async function exists(target) {
  try {
    return await stat(target);
  } catch {
    return null;
  }
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
      });
    }
  }
  return problems.sort((a, b) => a.categoryOrder - b.categoryOrder || a.code.localeCompare(b.code));
}
