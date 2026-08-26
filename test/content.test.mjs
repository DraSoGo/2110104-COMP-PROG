import test from 'node:test';
import assert from 'node:assert/strict';
import { adjacentProblems, buildCategoryTree, categoryIsOpen, filterProblems, groupProblemsByCategory, preserveScrollPosition, problemCategoryPath, slugify, summarizeProblems } from '../src/lib/content.js';

test('slugify keeps problem codes readable and makes Thai-safe folder names', () => {
  assert.equal(slugify('04_Array_23', 'ค่าเหยียบแผ่นดิน'), '04_Array_23-ค่าเหยียบแผ่นดิน');
  assert.equal(slugify('A10-0010', 'Hello, Croissant!'), 'A10-0010-Hello-Croissant');
});

test('filterProblems matches code, Thai title, category, and availability', () => {
  const problems = [
    { code: '01_Expr_11', title: 'Expression', category: 'Expressions & Math', pdf: 'a.pdf', solution: 'a.cpp', testcase: null },
    { code: '04_Array_23', title: 'ค่าเหยียบแผ่นดิน', category: 'Arrays & Grids', pdf: 'b.pdf', solution: null, testcase: null },
  ];
  assert.deepEqual(filterProblems(problems, { query: 'เหยียบ' }).map((p) => p.code), ['04_Array_23']);
  assert.deepEqual(filterProblems(problems, { query: 'expr' }).map((p) => p.code), ['01_Expr_11']);
  assert.deepEqual(filterProblems(problems, { category: 'Arrays & Grids' }).map((p) => p.code), ['04_Array_23']);
  assert.deepEqual(filterProblems(problems, { availability: 'solution' }).map((p) => p.code), ['01_Expr_11']);
  assert.deepEqual(filterProblems(problems, { availability: 'missing-solution' }).map((p) => p.code), ['04_Array_23']);
});

test('summarizeProblems counts categories and available artifacts', () => {
  const summary = summarizeProblems([
    { category: 'A', pdf: 'a.pdf', solution: 'a.cpp', testcase: null },
    { category: 'A', pdf: null, solution: 'b.cpp', testcase: 'testcase' },
    { category: 'B', pdf: 'c.pdf', solution: null, testcase: null },
  ]);
  assert.deepEqual(summary, { categories: 2, problems: 3, pdfs: 2, solutions: 2, testcaseSets: 1 });
});

test('groupProblemsByCategory preserves chapter order and problem order', () => {
  const groups = groupProblemsByCategory([
    { code: 'B02', category: 'Vectors', categoryOrder: 2 },
    { code: 'A02', category: 'Arrays', categoryOrder: 1 },
    { code: 'A01', category: 'Arrays', categoryOrder: 1 },
  ]);
  assert.deepEqual(groups.map((group) => [group.name, group.problems.map((problem) => problem.code)]), [
    ['Arrays', ['A01', 'A02']],
    ['Vectors', ['B02']],
  ]);
});

test('adjacentProblems returns previous and next records at list boundaries', () => {
  const problems = [{ id: 'a' }, { id: 'b' }, { id: 'c' }];
  assert.deepEqual(adjacentProblems(problems, 'a'), { previous: null, next: problems[1] });
  assert.deepEqual(adjacentProblems(problems, 'b'), { previous: problems[0], next: problems[2] });
  assert.deepEqual(adjacentProblems(problems, 'c'), { previous: problems[1], next: null });
});

test('categoryIsOpen lets an explicit user collapse override the active problem', () => {
  const base = { category: 'Arrays', activeCategory: 'Arrays', query: '', openCategories: new Set(['Arrays']) };
  assert.equal(categoryIsOpen({ ...base, closedCategories: new Set() }), true);
  assert.equal(categoryIsOpen({ ...base, closedCategories: new Set(['Arrays']) }), false);
  assert.equal(categoryIsOpen({ ...base, query: 'array', closedCategories: new Set(['Arrays']) }), true);
});

test('preserveScrollPosition restores scroll after a sidebar element is replaced', () => {
  let scroller = { scrollTop: 133 };
  preserveScrollPosition(() => scroller, () => { scroller = { scrollTop: 0 }; });
  assert.equal(scroller.scrollTop, 133);
});

test('buildCategoryTree creates nested course, exam, and Ovenbreak groups', () => {
  const problems = [
    { code: '01_A', category: 'Expressions & Basic Strings', categoryOrder: 1 },
    { code: 'M23', category: 'Midterm 2023', categoryOrder: 10 },
    { code: 'M24', category: 'Midterm 2024', categoryOrder: 11 },
    { code: 'MM', category: 'Midterm 2024 Mock Exam', categoryOrder: 12 },
    { code: 'F25', category: 'Final 2025', categoryOrder: 16 },
    { code: 'OV', category: 'Ovenbreak', categoryOrder: 17 },
    { code: 'QZ', category: 'Quizzes', categoryOrder: 18 },
  ];
  const tree = buildCategoryTree(problems);
  assert.deepEqual(tree.map((node) => [node.name, node.children.map((child) => child.name)]), [
    ['Course Topics', ['Expressions & Basic Strings']],
    ['Midterm', ['2023', '2024', 'Mock Exam']],
    ['Final', ['2025']],
    ['Ovenbreak', ['Final', 'Quiz']],
  ]);
});

test('problemCategoryPath returns parent and child breadcrumb labels', () => {
  assert.deepEqual(problemCategoryPath({ category: 'Midterm 2024', categoryOrder: 11 }), ['Midterm', '2024']);
  assert.deepEqual(problemCategoryPath({ category: 'Ovenbreak', categoryOrder: 17 }), ['Ovenbreak', 'Final']);
  assert.deepEqual(problemCategoryPath({ category: 'Quizzes', categoryOrder: 18 }), ['Ovenbreak', 'Quiz']);
});
