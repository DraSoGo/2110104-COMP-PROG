import test from 'node:test';
import assert from 'node:assert/strict';
import { highlightCpp } from '../src/lib/cpp-highlight.js';

test('highlightCpp marks C++ types, keywords, functions, and numbers', () => {
  const html = highlightCpp('int add(int a) { return a + 42; }');
  assert.match(html, /class="tok-type">int<\/span>/);
  assert.match(html, /class="tok-function">add<\/span>/);
  assert.match(html, /class="tok-keyword">return<\/span>/);
  assert.match(html, /class="tok-number">42<\/span>/);
});

test('highlightCpp distinguishes preprocessors, comments, strings, and characters', () => {
  const html = highlightCpp('#include <iostream>\n// hello\nstring s = "world"; char c = \'x\';');
  assert.match(html, /class="tok-preprocessor">#include &lt;iostream&gt;<\/span>/);
  assert.match(html, /class="tok-comment">\/\/ hello<\/span>/);
  assert.match(html, /class="tok-string">&quot;world&quot;<\/span>/);
  assert.match(html, /class="tok-string">&#39;x&#39;<\/span>/);
});

test('highlightCpp escapes source HTML before producing markup', () => {
  const html = highlightCpp('if (a < b && b > 0) cout << "<tag>";');
  assert.doesNotMatch(html, /<tag>/);
  assert.match(html, /&lt;tag&gt;/);
  assert.match(html, /class="tok-keyword">if<\/span>/);
});
