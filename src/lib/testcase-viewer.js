export function formatBytes(bytes) {
  if (bytes < 1024) return `${bytes} B`;
  const kilobytes = bytes / 1024;
  return `${Number(kilobytes.toFixed(1))} KB`;
}

async function loadSide(file, fetcher, resolvePath) {
  if (!file) return { file: null, content: null, error: 'FILE MISSING' };
  try {
    const response = await fetcher(resolvePath(file.path));
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    return { file, content: await response.text(), error: null };
  } catch (error) {
    return { file, content: null, error: error.message || 'LOAD FAILED' };
  }
}

export async function loadTestcasePair(pair, fetcher = fetch, resolvePath = (path) => path) {
  const [input, output] = await Promise.all([
    loadSide(pair.input, fetcher, resolvePath),
    loadSide(pair.output, fetcher, resolvePath),
  ]);
  return { id: pair.id, input, output };
}
