import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { recommendations, resolveRecommendations } from '../src/lib/recommendations.js';

const problems = JSON.parse(await readFile(new URL('../data/problems.json', import.meta.url), 'utf8'));

test('recommendations preserve every code from the legacy README without duplicates', () => {
  assert.equal(recommendations.length, 26);
  assert.equal(new Set(recommendations.map((item) => item.code)).size, 26);
});

test('all recommendations resolve to indexed problems, including 01_Str_31', () => {
  const resolved = resolveRecommendations(problems);
  assert.equal(resolved.filter((item) => item.problem).length, 26);
  assert.deepEqual(resolved.filter((item) => !item.problem), []);
  assert.equal(resolved.find((item) => item.code === '01_Str_31').title, 'Decimal → Fraction');
});

test('external learning resources use secure web links and known resource types', () => {
  const resources = recommendations.flatMap((item) => item.resources || []);
  assert.ok(resources.length > 0);
  for (const resource of resources) {
    assert.match(resource.url, /^https:\/\//);
    assert.ok(['DOC', 'VIDEO'].includes(resource.type));
    assert.ok(resource.label);
  }
});
