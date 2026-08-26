import { mkdir, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { scanProblemLibrary } from './lib/manifest.mjs';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const problems = await scanProblemLibrary(path.join(root, 'problems'));
await mkdir(path.join(root, 'data'), { recursive: true });
await writeFile(path.join(root, 'data', 'problems.json'), `${JSON.stringify(problems, null, 2)}\n`);
console.log(`Indexed ${problems.length} problems across ${new Set(problems.map((problem) => problem.category)).size} categories.`);
