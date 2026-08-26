import test from 'node:test';
import assert from 'node:assert/strict';
import { execFile } from 'node:child_process';
import { promisify } from 'node:util';

const execFileAsync = promisify(execFile);

test('content audit skips source-byte comparison when the original PDF directory is unavailable', async () => {
  const { stdout, stderr } = await execFileAsync(process.execPath, ['scripts/check-project.mjs'], {
    env: {
      ...process.env,
      CONTENT_SOURCE_DIR: '/tmp/cedt-source-that-does-not-exist',
    },
  });

  assert.equal(stderr, '');
  assert.match(stdout, /Original PDF source is not present; organized PDF paths and counts were validated\./);
});
