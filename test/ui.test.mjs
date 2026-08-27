import test from 'node:test';
import assert from 'node:assert/strict';
import { showTemporaryButtonStatus } from '../src/lib/ui.js';

test('showTemporaryButtonStatus resets the captured button without retaining an event object', () => {
  const button = { textContent: 'COPY' };
  let reset;
  showTemporaryButtonStatus(button, 'COPIED', 'COPY', 1300, (callback) => { reset = callback; });
  assert.equal(button.textContent, 'COPIED');
  reset();
  assert.equal(button.textContent, 'COPY');
});
