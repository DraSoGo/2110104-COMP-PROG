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
    testcases: [],
  });
});

test('scanProblemLibrary pairs testcase inputs and outputs with paths and byte sizes', async () => {
  const root = await mkdtemp(path.join(tmpdir(), 'problem-atlas-'));
  const folder = path.join(root, '02-conditionals', '02_If_11-Faculty-Code');
  await mkdir(path.join(folder, 'testcase', 'input'), { recursive: true });
  await mkdir(path.join(folder, 'testcase', 'output'), { recursive: true });
  await writeFile(path.join(folder, 'metadata.json'), JSON.stringify({ code: '02_If_11', title: 'Faculty Code', category: 'Conditionals', categoryOrder: 2 }));
  await writeFile(path.join(folder, 'testcase', 'input', '01.in'), '123\n');
  await writeFile(path.join(folder, 'testcase', 'output', '01.out'), 'ABC\n');

  const [problem] = await scanProblemLibrary(root);

  assert.equal(problem.testcase, 'problems/02-conditionals/02_If_11-Faculty-Code/testcase');
  assert.deepEqual(problem.testcases, [{
    id: '01',
    input: { path: 'problems/02-conditionals/02_If_11-Faculty-Code/testcase/input/01.in', size: 4 },
    output: { path: 'problems/02-conditionals/02_If_11-Faculty-Code/testcase/output/01.out', size: 4 },
  }]);
});
