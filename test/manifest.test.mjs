import test from 'node:test';
import assert from 'node:assert/strict';
import { mkdtemp, mkdir, writeFile } from 'node:fs/promises';
import { tmpdir } from 'node:os';
import path from 'node:path';
import { scanProblemLibrary } from '../scripts/lib/manifest.mjs';

test('scanProblemLibrary discovers artifacts without requiring testcases', async () => {
  const root = await mkdtemp(path.join(tmpdir(), 'problem-atlas-'));
  const folder = path.join(root, '01-expressions', '01_Expr_11-Expression');
  await mkdir(folder, { recursive: true });
  await writeFile(path.join(folder, 'metadata.json'), JSON.stringify({ code: '01_Expr_11', title: 'Expression', category: 'Expressions & Math', categoryOrder: 1 }));
  await writeFile(path.join(folder, 'problem.pdf'), 'pdf');
  await writeFile(path.join(folder, 'solution.cpp'), 'cpp');

  const result = await scanProblemLibrary(root);

  assert.equal(result.length, 1);
  assert.deepEqual(result[0], {
    id: '01-expressions/01_Expr_11-Expression',
    code: '01_Expr_11',
    title: 'Expression',
    category: 'Expressions & Math',
    categorySlug: '01-expressions',
    categoryOrder: 1,
    pdf: 'problems/01-expressions/01_Expr_11-Expression/problem.pdf',
    solution: 'problems/01-expressions/01_Expr_11-Expression/solution.cpp',
    solutionLanguage: 'cpp',
    testcase: null,
  });
});
