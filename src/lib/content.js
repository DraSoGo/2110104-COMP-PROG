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
