# CEDT Problem Atlas

CEDT Problem Atlas is a static web library for Computer Programming exercises, exams, and C++ solutions. It groups each problem statement and solution in one predictable folder, then builds the site from a generated manifest.

## Features

- Search by problem code, title, or chapter
- Filter by chapter and resource availability
- Dedicated problem views with embedded PDFs and source-code display
- Clear states for missing PDFs, solutions, and testcases
- Responsive layouts, keyboard focus styles, reduced-motion support, and dark mode
- Thai and English content support
- Hash-based routes that work on GitHub Pages without server rewrites

## Technology

The site uses semantic HTML, CSS, browser JavaScript modules, and Node.js build scripts. It has no runtime framework, backend, database, or package dependency.

## Folder structure

```text
.
├── data/problems.json       # generated content manifest
├── problems/
│   └── <category>/
│       └── <code>-<title>/
│           ├── metadata.json
│           ├── problem.pdf  # optional
│           ├── solution.cpp # optional
│           └── testcase/    # optional, maintained manually
├── scripts/                 # organizer, indexer, checks, build, server
├── src/                     # browser application and styles
├── test/                    # Node test suite
├── index.html
└── dist/                    # production build output
```

The original `Grader/` and `Ovenbreak/` solution trees remain in place. The organizer copied their files into `problems/`; it did not move or rewrite the originals.

## Requirements

- Node.js 20 or newer
- `pdftotext` and `pdfinfo` from Poppler only when importing new source PDFs

## Local development

```bash
npm run index
npm run dev
```

Open `http://localhost:4173`. The development server reads the project files directly.

## Tests and production build

```bash
npm test
npm run lint
npm run build
```

Run the full verification sequence with:

```bash
npm run verify
```

The production site is written to `dist/`. Preview it with:

```bash
npm run dev -- --dist
```

## Add a category

1. Create a filesystem-safe folder under `problems/`, such as `19-dynamic-programming`.
2. Use the same `category`, `categoryOrder`, and category folder for every problem in that chapter.
3. Run `npm run index`.

## Add a problem

Create `problems/<category>/<problem-code>-<problem-title>/metadata.json`:

```json
{
  "code": "ABC001",
  "title": "Sum of Two Numbers",
  "category": "Introduction",
  "categoryOrder": 0
}
```

Copy the statement to `problem.pdf`, then run `npm run index`. Keep the displayed title in `metadata.json` human-readable. Folder names should use safe characters and hyphens between words.

## Add a solution

Copy the existing solution into its problem folder as `solution.cpp`. Do not generate a placeholder for an unsolved problem. Run `npm run index` afterward.

## Add testcases later

Create `testcase/` inside the problem folder and place your files under it without changing their internal names or structure. Run `npm run index` to expose the testcase status on the site.

> Testcase content is maintained manually. The scripts do not create, execute, validate, rename, or modify testcase files.

## Re-import the supplied PDF collection

The organizer defaults to the source path used for this import. You may pass another read-only PDF root:

```bash
npm run organize -- /absolute/path/to/pdf-source
```

The organizer uses exclusive copies. It skips byte-identical destinations and exits with a conflict report when an existing destination differs.

## GitHub Pages

1. Open the repository's **Settings → Pages** page.
2. Set **Build and deployment → Source** to **GitHub Actions**.
3. Push to `main`. `.github/workflows/pages.yml` runs the tests, content audit, and production build before deploying `dist/`.

Pull requests targeting `main` run the same checks without deploying. You can also run the workflow manually from the Actions tab.

All URLs are relative and page navigation uses URL hashes, so the build works from a repository subpath such as `https://username.github.io/repository/`.
