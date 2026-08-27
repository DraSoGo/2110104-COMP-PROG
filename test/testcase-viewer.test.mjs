import test from 'node:test';
import assert from 'node:assert/strict';
import { formatBytes, loadTestcasePair } from '../src/lib/testcase-viewer.js';

test('formatBytes keeps testcase sizes compact and readable', () => {
  assert.equal(formatBytes(0), '0 B');
  assert.equal(formatBytes(999), '999 B');
  assert.equal(formatBytes(1536), '1.5 KB');
});

test('loadTestcasePair loads input and output independently', async () => {
  const pair = { id: '01', input: { path: 'input/01.in', size: 4 }, output: { path: 'output/01.out', size: 3 } };
  const fetcher = async (path) => path.includes('input')
    ? { ok: true, text: async () => '42\n' }
    : { ok: false, status: 404, text: async () => '' };

  const loaded = await loadTestcasePair(pair, fetcher, (path) => `/base/${path}`);

  assert.equal(loaded.input.content, '42\n');
  assert.equal(loaded.input.error, null);
  assert.equal(loaded.output.content, null);
  assert.equal(loaded.output.error, 'HTTP 404');
});
