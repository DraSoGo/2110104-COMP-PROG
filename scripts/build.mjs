import { cp, mkdir, rm, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { scanProblemLibrary } from './lib/manifest.mjs';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const dist = path.join(root, 'dist');
await rm(dist, { recursive: true, force: true });
await mkdir(dist, { recursive: true });
const problems = await scanProblemLibrary(path.join(root, 'problems'));
await mkdir(path.join(root, 'data'), { recursive: true });
await writeFile(path.join(root, 'data', 'problems.json'), `${JSON.stringify(problems, null, 2)}\n`);
for (const entry of ['index.html', 'src', 'data', 'problems']) await cp(path.join(root, entry), path.join(dist, entry), { recursive: true });
await writeFile(path.join(dist, '.nojekyll'), '');
console.log(`Built dist/ with ${problems.length} indexed problems.`);
