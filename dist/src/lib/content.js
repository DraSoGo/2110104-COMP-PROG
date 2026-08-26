export function slugify(code, title) {
  const safeCode = String(code).trim().replace(/[^\p{L}\p{N}_-]+/gu, '-').replace(/^-+|-+$/g, '');
  const safeTitle = String(title)
    .normalize('NFC')
    .trim()
    .replace(/[’']/g, '')
    .replace(/[^\p{L}\p{M}\p{N}]+/gu, '-')
    .replace(/^-+|-+$/g, '');
  return safeTitle ? `${safeCode}-${safeTitle}` : safeCode;
}

export function filterProblems(problems, filters = {}) {
  const query = (filters.query || '').trim().toLocaleLowerCase();
  return problems.filter((problem) => {
    const haystack = `${problem.code} ${problem.title} ${problem.category}`.toLocaleLowerCase();
    if (query && !haystack.includes(query)) return false;
    if (filters.category && filters.category !== 'all' && problem.category !== filters.category) return false;
    if (filters.availability === 'pdf' && !problem.pdf) return false;
    if (filters.availability === 'solution' && !problem.solution) return false;
    if (filters.availability === 'testcase' && !problem.testcase) return false;
    if (filters.availability === 'missing-solution' && problem.solution) return false;
    if (filters.availability === 'missing-testcase' && problem.testcase) return false;
    return true;
  });
}

export function summarizeProblems(problems) {
  return {
    categories: new Set(problems.map((problem) => problem.category)).size,
    problems: problems.length,
    pdfs: problems.filter((problem) => problem.pdf).length,
    solutions: problems.filter((problem) => problem.solution).length,
    testcaseSets: problems.filter((problem) => problem.testcase).length,
  };
}

export function groupProblemsByCategory(problems) {
  const groups = new Map();
  for (const problem of problems) {
    if (!groups.has(problem.category)) groups.set(problem.category, { name: problem.category, order: problem.categoryOrder, problems: [] });
    groups.get(problem.category).problems.push(problem);
  }
  return [...groups.values()]
    .sort((a, b) => a.order - b.order)
    .map((group) => ({ ...group, problems: group.problems.sort((a, b) => a.code.localeCompare(b.code)) }));
}

export function adjacentProblems(problems, id) {
  const index = problems.findIndex((problem) => problem.id === id);
  if (index < 0) return { previous: null, next: null };
  return { previous: problems[index - 1] || null, next: problems[index + 1] || null };
}

export function categoryIsOpen({ category, activeCategory, query, openCategories, closedCategories }) {
  if (query) return true;
  if (closedCategories.has(category)) return false;
  return openCategories.has(category) || activeCategory === category;
}

export function preserveScrollPosition(getScroller, render) {
  const scrollTop = getScroller()?.scrollTop ?? 0;
  render();
  const nextScroller = getScroller();
  if (nextScroller) nextScroller.scrollTop = scrollTop;
}

function categoryDescriptor(problem) {
  const order = problem.categoryOrder;
  if (order <= 9) return { parentId: 'course-topics', parentName: 'Course Topics', parentCode: '00-09', childId: `topic-${order}`, childName: problem.category, childCode: String(order).padStart(2, '0') };
  if (order <= 12) {
    const child = order === 10 ? ['2023', '2023'] : order === 11 ? ['2024', '2024'] : ['mock', 'Mock Exam'];
    return { parentId: 'midterm', parentName: 'Midterm', parentCode: 'MID', childId: `midterm-${child[0]}`, childName: child[1], childCode: order === 12 ? 'M' : child[1].slice(-2) };
  }
  if (order <= 16) {
    const child = order === 13 ? ['2023', '2023'] : order === 14 ? ['2024', '2024'] : order === 15 ? ['mock', 'Mock Exam'] : ['2025', '2025'];
    return { parentId: 'final', parentName: 'Final', parentCode: 'FIN', childId: `final-${child[0]}`, childName: child[1], childCode: order === 15 ? 'M' : child[1].slice(-2) };
  }
  const isQuiz = order === 18;
  return { parentId: 'ovenbreak', parentName: 'Ovenbreak', parentCode: 'OVN', childId: isQuiz ? 'ovenbreak-quiz' : 'ovenbreak-final', childName: isQuiz ? 'Quiz' : 'Final', childCode: isQuiz ? 'Q' : 'F' };
}

export function buildCategoryTree(problems) {
  const parents = new Map();
  for (const problem of problems) {
    const descriptor = categoryDescriptor(problem);
    if (!parents.has(descriptor.parentId)) parents.set(descriptor.parentId, { id: descriptor.parentId, name: descriptor.parentName, code: descriptor.parentCode, order: problem.categoryOrder, children: [] });
    const parent = parents.get(descriptor.parentId);
    let child = parent.children.find((item) => item.id === descriptor.childId);
    if (!child) {
      child = { id: descriptor.childId, name: descriptor.childName, code: descriptor.childCode, category: problem.category, order: problem.categoryOrder, problems: [] };
      parent.children.push(child);
    }
    child.problems.push(problem);
    parent.order = Math.min(parent.order, problem.categoryOrder);
  }
  return [...parents.values()]
    .sort((a, b) => a.order - b.order)
    .map((parent) => ({ ...parent, children: parent.children.sort((a, b) => a.order - b.order).map((child) => ({ ...child, problems: child.problems.sort((a, b) => a.code.localeCompare(b.code)) })) }));
}

export function problemCategoryPath(problem) {
  const descriptor = categoryDescriptor(problem);
  return [descriptor.parentName, descriptor.childName];
}
