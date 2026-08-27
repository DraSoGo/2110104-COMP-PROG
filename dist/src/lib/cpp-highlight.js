const keywords = new Set([
  'alignas', 'alignof', 'asm', 'break', 'case', 'catch', 'class', 'concept', 'const', 'constexpr', 'continue', 'co_await', 'co_return', 'co_yield', 'default', 'delete', 'do', 'else', 'enum', 'explicit', 'export', 'extern', 'false', 'for', 'friend', 'goto', 'if', 'inline', 'namespace', 'new', 'noexcept', 'nullptr', 'operator', 'private', 'protected', 'public', 'requires', 'return', 'sizeof', 'static', 'static_assert', 'struct', 'switch', 'template', 'this', 'throw', 'true', 'try', 'typedef', 'typename', 'union', 'using', 'virtual', 'volatile', 'while',
]);

const types = new Set([
  'auto', 'bool', 'char', 'char16_t', 'char32_t', 'char8_t', 'double', 'float', 'int', 'long', 'short', 'signed', 'unsigned', 'void', 'wchar_t', 'size_t', 'string', 'vector', 'array', 'deque', 'list', 'map', 'multimap', 'multiset', 'pair', 'queue', 'set', 'stack', 'unordered_map', 'unordered_set',
]);

function escapeHtml(value) {
  return value.replace(/[&<>'"]/g, (char) => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', "'": '&#39;', '"': '&quot;' })[char]);
}

function token(kind, value) {
  return `<span class="tok-${kind}">${escapeHtml(value)}</span>`;
}

export function highlightCpp(source) {
  let html = '';
  let index = 0;

  while (index < source.length) {
    const rest = source.slice(index);
    const lineStart = source.lastIndexOf('\n', index - 1) + 1;

    if (source[index] === '#' && source.slice(lineStart, index).trim() === '') {
      const end = source.indexOf('\n', index);
      const stop = end < 0 ? source.length : end;
      html += token('preprocessor', source.slice(index, stop));
      index = stop;
      continue;
    }

    if (rest.startsWith('//')) {
      const end = source.indexOf('\n', index);
      const stop = end < 0 ? source.length : end;
      html += token('comment', source.slice(index, stop));
      index = stop;
      continue;
    }

    if (rest.startsWith('/*')) {
      const end = source.indexOf('*/', index + 2);
      const stop = end < 0 ? source.length : end + 2;
      html += token('comment', source.slice(index, stop));
      index = stop;
      continue;
    }

    if (source[index] === '"' || source[index] === "'") {
      const quote = source[index];
      let stop = index + 1;
      while (stop < source.length) {
        if (source[stop] === '\\') stop += 2;
        else if (source[stop++] === quote) break;
      }
      html += token('string', source.slice(index, stop));
      index = stop;
      continue;
    }

    const number = rest.match(/^(?:0[xX][\da-fA-F]+|0[bB][01]+|\d+(?:\.\d+)?(?:[eE][+-]?\d+)?)[uUlLfF]*/)?.[0];
    if (number) {
      html += token('number', number);
      index += number.length;
      continue;
    }

    const identifier = rest.match(/^[A-Za-z_]\w*/)?.[0];
    if (identifier) {
      const next = source.slice(index + identifier.length).match(/^\s*(.)/)?.[1];
      const kind = keywords.has(identifier) ? 'keyword' : types.has(identifier) ? 'type' : next === '(' ? 'function' : null;
      html += kind ? token(kind, identifier) : escapeHtml(identifier);
      index += identifier.length;
      continue;
    }

    html += escapeHtml(source[index]);
    index += 1;
  }

  return html;
}
