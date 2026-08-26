import { adjacentProblems, buildCategoryTree, categoryIsOpen, filterProblems, groupProblemsByCategory, preserveScrollPosition, problemCategoryPath, summarizeProblems } from './lib/content.js';

const app = document.querySelector('#app');
const state = { problems: [], query: '', openCategories: new Set(), closedCategories: new Set(), sidebarOpen: false };

const icon = (name) => ({
  menu: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M4 7h16M4 12h16M4 17h16"/></svg>',
  search: '<svg viewBox="0 0 24 24" aria-hidden="true"><circle cx="11" cy="11" r="6.5"/><path d="m16 16 4 4"/></svg>',
  chevron: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="m9 6 6 6-6 6"/></svg>',
  file: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M6 3h8l4 4v14H6zM14 3v5h5"/></svg>',
  code: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="m9 7-5 5 5 5m6-10 5 5-5 5"/></svg>',
  flask: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M9 3h6M10 3v6l-5 9a2 2 0 0 0 2 3h10a2 2 0 0 0 2-3l-5-9V3M7 16h10"/></svg>',
  sun: '<svg viewBox="0 0 24 24" aria-hidden="true"><circle cx="12" cy="12" r="4"/><path d="M12 2v2m0 16v2M4.9 4.9l1.4 1.4m11.4 11.4 1.4 1.4M2 12h2m16 0h2M4.9 19.1l1.4-1.4M17.7 6.3l1.4-1.4"/></svg>',
  moon: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M20 15.5A8 8 0 0 1 8.5 4 8.2 8.2 0 1 0 20 15.5Z"/></svg>',
  external: '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M14 4h6v6M20 4l-9 9M19 14v6H4V5h6"/></svg>',
}[name]);

function escapeHtml(value) {
  return String(value).replace(/[&<>'"]/g, (char) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', "'": '&#39;', '"': '&quot;' })[char]);
}

function asset(path) { return new URL(`../${path}`, import.meta.url).href; }
function routeId() { return location.hash.startsWith('#/problem/') ? decodeURIComponent(location.hash.slice(10)) : null; }
function activeProblem() { return state.problems.find((problem) => problem.id === routeId()) || null; }
function resourceDot(available, label) { return `<span class="resource-dot ${available ? 'ready' : ''}" title="${escapeHtml(label)}"><span></span>${escapeHtml(label)}</span>`; }

function categoryCode(group) {
  const prefix = group.problems[0]?.categorySlug.match(/^([0-9]+)/)?.[1] || '--';
  return prefix.padStart(2, '0');
}

function sidebarMarkup() {
  const filtered = filterProblems(state.problems, { query: state.query });
  const tree = buildCategoryTree(state.problems);
  const active = activeProblem();
  const activeNodes = new Set();
  for (const parent of tree) for (const child of parent.children) if (child.problems.some((problem) => problem.id === active?.id)) { activeNodes.add(parent.id); activeNodes.add(child.id); }
  const isOpen = (id) => categoryIsOpen({ category: id, activeCategory: activeNodes.has(id) ? id : null, query: state.query, openCategories: state.openCategories, closedCategories: state.closedCategories });
  return `<aside class="sidebar ${state.sidebarOpen ? 'is-open' : ''}" aria-label="Problem navigation">
    <div class="sidebar-head"><span>COURSE_INDEX</span><button class="sidebar-close" type="button" aria-label="Close problem navigation">×</button></div>
    <nav class="course-tree" id="course-tree">
      ${tree.map((parent) => {
        const visibleChildren = parent.children.map((child) => ({ ...child, visible: child.problems.filter((problem) => filtered.includes(problem)) })).filter((child) => !state.query || child.visible.length);
        if (!visibleChildren.length) return '';
        const parentOpen = isOpen(parent.id);
        const parentCount = visibleChildren.reduce((count, child) => count + (state.query ? child.visible.length : child.problems.length), 0);
        return `<section class="tree-group tree-parent ${parentOpen ? 'open' : ''}">
          <button class="tree-heading tree-parent-heading" type="button" data-node="${parent.id}" aria-expanded="${parentOpen}">
            ${icon('chevron')}<span class="tree-code">${escapeHtml(parent.code)}</span><strong>${escapeHtml(parent.name)}</strong><span class="tree-count">${parentCount}</span>
          </button>
          <div class="tree-children" ${parentOpen ? '' : 'hidden'}>
            ${visibleChildren.map((child) => {
              const childOpen = isOpen(child.id);
              const problems = state.query ? child.visible : child.problems;
              return `<section class="tree-child ${childOpen ? 'open' : ''}">
                <button class="tree-heading tree-child-heading" type="button" data-node="${child.id}" data-category="${escapeHtml(child.category)}" aria-expanded="${childOpen}">
                  ${icon('chevron')}<span class="tree-code">${escapeHtml(child.code)}</span><strong>${escapeHtml(child.name)}</strong><span class="tree-count">${problems.length}</span>
                </button>
                <div class="tree-problems" ${childOpen ? '' : 'hidden'}>${problems.map((problem) => `<a class="tree-problem ${active?.id === problem.id ? 'active' : ''}" href="#/problem/${encodeURIComponent(problem.id)}">
                  <span class="tree-line"></span><span><code>${escapeHtml(problem.code)}</code><small>${escapeHtml(problem.title)}</small></span>
                  <span class="mini-status ${problem.solution ? 'has-solution' : ''}" title="${problem.solution ? 'Solution available' : 'Solution pending'}"></span>
                </a>`).join('')}</div>
              </section>`;
            }).join('')}
          </div>
        </section>`;
      }).join('')}
    </nav>
    <div class="sidebar-foot"><span><i class="status-led"></i>SYSTEM ONLINE</span><span>v1.0.0</span></div>
  </aside>`;
}

function shellMarkup() {
  const summary = summarizeProblems(state.problems);
  return `<header class="topbar">
    <button class="menu-button" type="button" aria-label="Open problem navigation">${icon('menu')}</button>
    <a class="wordmark" href="#/"><span class="prompt-mark">&gt;_</span><span><strong>2110104</strong><small>COMPUTER PROGRAMMING</small></span></a>
    <label class="global-search">${icon('search')}<span class="sr-only">Search problems</span><input type="search" id="global-search" placeholder="Search problems..." autocomplete="off" value="${escapeHtml(state.query)}"><kbd>/</kbd></label>
    <div class="system-summary"><span>${summary.problems}<small>PROBLEMS</small></span><span>${summary.pdfs}<small>PDF</small></span><span>${summary.solutions}<small>SOLUTIONS</small></span></div>
    <button class="theme-button" type="button" aria-label="Toggle color theme">${document.documentElement.dataset.theme === 'dark' ? icon('sun') : icon('moon')}</button>
  </header>
  <div class="workspace">${sidebarMarkup()}<button class="sidebar-scrim" type="button" aria-label="Close navigation"></button><main id="main" tabindex="-1"></main></div>`;
}

function overviewMarkup() {
  const summary = summarizeProblems(state.problems);
  const groups = groupProblemsByCategory(state.problems);
  return `<div class="overview view-enter">
    <div class="terminal-label"><span>~/cedt/com_prog</span><span>overview.exe</span></div>
    <section class="overview-hero">
      <p class="command-line"><span>$</span> ./browse-problems --course 2110104</p>
      <h1>Problem<br><span>Browser</span><i>_</i></h1>
      <p class="overview-copy">Browse course exercises, exam statements, and existing C++ solutions from one focused workspace.</p>
    </section>
    <section class="metric-grid" aria-label="Library summary">
      <article><span>01</span><strong>${summary.problems}</strong><small>PROBLEMS INDEXED</small></article>
      <article><span>02</span><strong>${summary.categories}</strong><small>TOPICS / EXAMS</small></article>
      <article><span>03</span><strong>${summary.pdfs}</strong><small>PDF STATEMENTS</small></article>
      <article><span>04</span><strong>${summary.solutions}</strong><small>C++ SOLUTIONS</small></article>
    </section>
    <section class="overview-grid">
      <div class="quick-start"><div class="panel-title"><span>QUICK_START.md</span><i></i></div><ol><li><span>01</span><div><strong>Choose a chapter</strong><p>Expand a topic in the navigation tree.</p></div></li><li><span>02</span><div><strong>Open a problem</strong><p>Read its statement without leaving the workspace.</p></div></li><li><span>03</span><div><strong>Study the source</strong><p>Switch to the solution tab when it is available.</p></div></li></ol></div>
      <div class="topic-terminal"><div class="panel-title"><span>topics.list</span><i></i></div><div class="terminal-body">${groups.slice(0,10).map((group) => `<button type="button" data-jump="${escapeHtml(group.name)}"><span>${categoryCode(group)}</span><strong>${escapeHtml(group.name)}</strong><small>${group.problems.length}</small></button>`).join('')}<p><span>$</span> select a topic to continue<span class="cursor">█</span></p></div></div>
    </section>
  </div>`;
}

function emptyResource(kind, title, message) {
  return `<div class="empty-resource"><div class="empty-icon">${icon(kind)}</div><code>STATUS: NOT_FOUND</code><h3>${escapeHtml(title)}</h3><p>${escapeHtml(message)}</p></div>`;
}

function problemMarkup(problem) {
  const ordered = groupProblemsByCategory(state.problems).flatMap((group) => group.problems);
  const adjacent = adjacentProblems(ordered, problem.id);
  const categoryPath = problemCategoryPath(problem);
  return `<div class="problem-view view-enter">
    <div class="terminal-label"><span>~/problems/${escapeHtml(problem.categorySlug)}</span><span>${escapeHtml(problem.code)}</span></div>
    <nav class="breadcrumbs" aria-label="Breadcrumb"><a href="#/">ROOT</a><span>/</span><button type="button" data-jump="${escapeHtml(problem.category)}">${escapeHtml(categoryPath[0])}</button><span>/</span><button type="button" data-jump="${escapeHtml(problem.category)}">${escapeHtml(categoryPath[1])}</button><span>/</span><strong>${escapeHtml(problem.code)}</strong></nav>
    <header class="problem-head">
      <div><code>${escapeHtml(problem.code)}</code><h1>${escapeHtml(problem.title)}</h1></div>
      <div class="artifact-status">${resourceDot(problem.pdf, 'PDF')}${resourceDot(problem.solution, 'SOLUTION')}${resourceDot(problem.testcase, 'TESTCASE')}</div>
    </header>
    <div class="tab-bar" role="tablist" aria-label="Problem resources">
      <button role="tab" aria-selected="true" data-tab="statement">${icon('file')}<span>STATEMENT</span><small>${problem.pdf ? 'READY' : 'MISSING'}</small></button>
      <button role="tab" aria-selected="false" data-tab="solution">${icon('code')}<span>SOLUTION</span><small>${problem.solution ? 'READY' : 'MISSING'}</small></button>
      <button role="tab" aria-selected="false" data-tab="testcases">${icon('flask')}<span>TESTCASES</span><small>${problem.testcase ? 'READY' : 'PENDING'}</small></button>
    </div>
    <section class="tab-panel" id="panel-statement" role="tabpanel">
      ${problem.pdf ? `<div class="resource-toolbar"><span>${icon('file')}<code>problem.pdf</code></span><div><a href="${asset(problem.pdf)}" target="_blank" rel="noopener">OPEN ${icon('external')}</a><a href="${asset(problem.pdf)}" download>DOWNLOAD</a></div></div><object class="pdf-viewer" data="${asset(problem.pdf)}" type="application/pdf">${emptyResource('file','PDF preview unavailable','Open the statement in a new browser tab.')}</object>` : emptyResource('file','Statement unavailable','No PDF is associated with this problem yet.')}
    </section>
    <section class="tab-panel" id="panel-solution" role="tabpanel" hidden><div id="solution-content">${problem.solution ? '<div class="inline-loader"><span></span>READING solution.cpp...</div>' : emptyResource('code','Solution unavailable','No existing solution is associated with this problem.')}</div></section>
    <section class="tab-panel" id="panel-testcases" role="tabpanel" hidden>${problem.testcase ? `<div class="testcase-state">${icon('flask')}<div><code>TESTCASE_SET: READY</code><h3>Testcases available</h3><p>This folder is maintained manually.</p></div><a href="${asset(problem.testcase)}">OPEN FOLDER</a></div>` : emptyResource('flask','Testcases pending','Testcase content will be added and maintained manually.')}</section>
    <nav class="problem-pagination" aria-label="Adjacent problems">
      ${adjacent.previous ? `<a href="#/problem/${encodeURIComponent(adjacent.previous.id)}"><small>← PREVIOUS</small><strong>${escapeHtml(adjacent.previous.code)}</strong><span>${escapeHtml(adjacent.previous.title)}</span></a>` : '<span></span>'}
      ${adjacent.next ? `<a class="next" href="#/problem/${encodeURIComponent(adjacent.next.id)}"><small>NEXT →</small><strong>${escapeHtml(adjacent.next.code)}</strong><span>${escapeHtml(adjacent.next.title)}</span></a>` : '<span></span>'}
    </nav>
  </div>`;
}

async function loadSolution(problem) {
  const container = document.querySelector('#solution-content');
  try {
    const response = await fetch(asset(problem.solution));
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    const source = await response.text();
    container.innerHTML = `<div class="code-head"><span><i></i><i></i><i></i><code>solution.cpp</code></span><button type="button" id="copy-code">COPY</button></div><pre tabindex="0"><code>${escapeHtml(source)}</code></pre>`;
    document.querySelector('#copy-code').addEventListener('click', async (event) => { await navigator.clipboard.writeText(source); event.currentTarget.textContent = 'COPIED'; setTimeout(() => { event.currentTarget.textContent = 'COPY'; }, 1300); });
  } catch {
    container.innerHTML = emptyResource('code','Solution could not be loaded','Open the source file directly from its problem folder.');
  }
}

function bindShell() {
  const search = document.querySelector('#global-search');
  search.addEventListener('input', (event) => { state.query = event.target.value; updateSidebar(); });
  document.addEventListener('keydown', focusSearch);
  document.querySelector('.menu-button').addEventListener('click', () => { state.sidebarOpen = true; updateSidebar(); });
  document.querySelector('.theme-button').addEventListener('click', toggleTheme);
}

function focusSearch(event) {
  if (event.key === '/' && !['INPUT','TEXTAREA'].includes(document.activeElement.tagName)) { event.preventDefault(); document.querySelector('#global-search')?.focus(); }
}

function toggleTheme() {
  const theme = document.documentElement.dataset.theme === 'dark' ? 'light' : 'dark';
  document.documentElement.dataset.theme = theme;
  localStorage.setItem('problem-browser-theme', theme);
  document.querySelector('.theme-button').innerHTML = theme === 'dark' ? icon('sun') : icon('moon');
}

function updateSidebar() {
  preserveScrollPosition(
    () => document.querySelector('#course-tree'),
    () => { document.querySelector('.sidebar').outerHTML = sidebarMarkup(); },
  );
  bindSidebar();
}

function bindSidebar() {
  document.querySelectorAll('.tree-heading[data-node]').forEach((button) => button.addEventListener('click', () => {
    const category = button.dataset.node;
    if (button.getAttribute('aria-expanded') === 'true') {
      state.openCategories.delete(category);
      state.closedCategories.add(category);
    } else {
      state.closedCategories.delete(category);
      state.openCategories.add(category);
    }
    updateSidebar();
  }));
  const close = () => { state.sidebarOpen = false; updateSidebar(); };
  document.querySelector('.sidebar-close').addEventListener('click', close);
  document.querySelector('.sidebar-scrim').onclick = close;
  document.querySelectorAll('.tree-problem').forEach((link) => link.addEventListener('click', () => { state.sidebarOpen = false; }));
}

function jumpToCategory(category) {
  const tree = buildCategoryTree(state.problems);
  const parent = tree.find((node) => node.children.some((child) => child.category === category));
  const child = parent?.children.find((node) => node.category === category);
  for (const id of [parent?.id, child?.id].filter(Boolean)) { state.closedCategories.delete(id); state.openCategories.add(id); }
  state.query = '';
  state.sidebarOpen = matchMedia('(max-width: 760px)').matches;
  document.querySelector('#global-search').value = '';
  updateSidebar();
  document.querySelector(`.tree-child-heading[data-category="${CSS.escape(category)}"]`)?.scrollIntoView({ block: 'center' });
}

function bindView(problem) {
  document.querySelectorAll('[data-jump]').forEach((button) => button.addEventListener('click', () => jumpToCategory(button.dataset.jump)));
  if (!problem) return;
  document.querySelectorAll('[role="tab"]').forEach((tab) => tab.addEventListener('click', () => {
    document.querySelectorAll('[role="tab"]').forEach((item) => item.setAttribute('aria-selected', String(item === tab)));
    document.querySelectorAll('[role="tabpanel"]').forEach((panel) => { panel.hidden = panel.id !== `panel-${tab.dataset.tab}`; });
    if (tab.dataset.tab === 'solution' && problem.solution && !document.querySelector('#solution-content pre')) loadSolution(problem);
  }));
}

function renderRoute() {
  const problem = activeProblem();
  document.title = problem ? `${problem.code} ${problem.title} · Problem Browser` : '2110104 Computer Programming · Problem Browser';
  document.querySelector('#main').innerHTML = problem ? problemMarkup(problem) : overviewMarkup();
  bindView(problem);
  updateSidebar();
  document.querySelector('#main').scrollTo(0, 0);
}

async function boot() {
  document.documentElement.dataset.theme = localStorage.getItem('problem-browser-theme') || 'dark';
  try {
    const response = await fetch(asset('data/problems.json'));
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    state.problems = await response.json();
    const firstParent = buildCategoryTree(state.problems)[0];
    state.openCategories.add(firstParent?.id);
    state.openCategories.add(firstParent?.children[0]?.id);
    app.className = 'app-shell';
    app.removeAttribute('role');
    app.innerHTML = shellMarkup();
    bindShell(); bindSidebar(); renderRoute();
    window.addEventListener('hashchange', renderRoute);
  } catch (error) {
    app.innerHTML = `<div class="fatal-error"><code>BOOT_ERROR ${escapeHtml(error.message)}</code><h1>Problem index unavailable</h1><button type="button" onclick="location.reload()">RETRY</button></div>`;
  }
}

boot();
