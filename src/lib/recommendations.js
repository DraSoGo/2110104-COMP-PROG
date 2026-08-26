export const recommendations = [
  { code: '01_Expr_31', track: 'FOUNDATIONS', technique: 'Interesting math problem', resources: [{ type: 'DOC', label: 'Circular math', url: 'https://www.opendurian.com/news/mathcirdec/' }] },
  { code: '02_If_31', track: 'FOUNDATIONS', technique: 'Functions and leap-year logic', resources: [{ type: 'DOC', label: 'C++ functions', url: 'https://www.geeksforgeeks.org/cpp/functions-in-cpp/' }] },
  { code: '03_Loop_15', track: 'FOUNDATIONS', technique: 'Ternary operator', resources: [{ type: 'DOC', label: 'Conditional operator', url: 'https://www.geeksforgeeks.org/cpp/cpp-ternary-or-conditional-operator/' }] },
  { code: '03_Loop_22', track: 'FOUNDATIONS', technique: 'Prime factorization' },
  { code: '03_Loop_31', track: 'FOUNDATIONS', technique: 'Power and digit helper functions' },
  { code: '04_Array_14', track: 'ARRAYS', technique: '2D prefix sum', resources: [{ type: 'DOC', label: '2D prefix sums', url: 'https://www.geeksforgeeks.org/dsa/prefix-sum-2d-array/' }, { type: 'VIDEO', label: 'Prefix sum lesson', url: 'https://www.youtube.com/watch?v=WibxoqMSMCw' }] },
  { code: '04_Array_28', track: 'ARRAYS', technique: 'Character normalization with tolower' },
  { code: '04_Array_29', track: 'ARRAYS', technique: 'C++ structs', resources: [{ type: 'DOC', label: 'Structures in C++', url: 'https://www.geeksforgeeks.org/cpp/structures-in-cpp/' }] },
  { code: '04_Array_32', track: 'ARRAYS', technique: 'Stateful array simulation' },
  { code: '05_String_12', track: 'STRINGS', technique: 'Arithmetic with numeric strings' },
  { code: '05_String_21', track: 'STRINGS', technique: 'isupper, islower and isdigit' },
  { code: '05_String_23', track: 'STRINGS', technique: 'String parsing with math' },
  { code: '05_String_31', track: 'STRINGS', technique: 'Bitwise operators and isalpha', resources: [{ type: 'DOC', label: 'Bitwise operators', url: 'https://www.geeksforgeeks.org/cpp/cpp-bitwise-operators/' }, { type: 'VIDEO', label: 'Bitwise lesson', url: 'https://www.youtube.com/watch?v=jlQmeyce65Q' }] },
  { code: '06_Vector_11', track: 'STL', technique: 'Deque', resources: [{ type: 'DOC', label: 'Deque in C++', url: 'https://www.geeksforgeeks.org/cpp/deque-cpp-stl/' }] },
  { code: '06_Vector_14', track: 'STL', technique: 'Set', resources: [{ type: 'DOC', label: 'Set in C++', url: 'https://www.geeksforgeeks.org/cpp/set-in-cpp-stl/' }] },
  { code: '06_Vector_23', track: 'STL', technique: 'Sorting structs with operator<', resources: [{ type: 'DOC', label: 'Struct sorting', url: 'https://www.daniweb.com/programming/software-development/threads/489915/sorting-of-struct-using-bool-operator' }] },
  { code: '06_Vector_32', track: 'STL', technique: 'Custom sort comparator', resources: [{ type: 'DOC', label: 'Comparators in C++', url: 'https://www.geeksforgeeks.org/cpp/comparator-in-cpp/' }] },
  { code: '06_Vector_35', track: 'STL', technique: 'Container-driven parsing' },
  { code: '07_Set_11', track: 'STL', technique: 'Multiset', resources: [{ type: 'DOC', label: 'Multiset in C++', url: 'https://www.geeksforgeeks.org/cpp/multiset-in-cpp-stl/' }] },
  { code: '08_Map_21', track: 'LOOKUP', technique: 'Preserving order with a vector' },
  { code: '08_Map_23', track: 'LOOKUP', technique: 'Range-based for loops', resources: [{ type: 'DOC', label: 'Range-based loops', url: 'https://www.geeksforgeeks.org/cpp/range-based-loop-c/' }] },
  { code: '08_Map_26', track: 'LOOKUP', technique: 'Introductory graph modeling' },
  { code: '08_Map_27', track: 'LOOKUP', technique: 'Searching with string::npos' },
  { code: '08_Map_31', track: 'LOOKUP', technique: 'Arrays inside structs' },
  { code: '09_Recur_33', track: 'GRAPH', technique: 'DFS with an explicit stack', resources: [{ type: 'DOC', label: 'Stack in C++', url: 'https://www.geeksforgeeks.org/cpp/stack-in-cpp-stl/' }, { type: 'DOC', label: 'Iterative DFS', url: 'https://www.geeksforgeeks.org/dsa/iterative-depth-first-traversal/' }, { type: 'VIDEO', label: 'DFS lesson', url: 'https://www.youtube.com/watch?v=pBasV9jlQ0w' }] },
  { code: '09_Recur_41', track: 'GRAPH', technique: 'BFS with a queue', resources: [{ type: 'DOC', label: 'Queue in C++', url: 'https://www.geeksforgeeks.org/cpp/queue-cpp-stl/' }, { type: 'DOC', label: 'Breadth-first search', url: 'https://www-geeksforgeeks-org.translate.goog/python/python-program-for-breadth-first-search-or-bfs-for-a-graph/?_x_tr_sl=en&_x_tr_tl=th&_x_tr_hl=th&_x_tr_pto=tc&_x_tr_hist=true' }, { type: 'VIDEO', label: 'BFS lesson', url: 'https://www.youtube.com/watch?v=oOlN-qWJzzA' }] },
];

export function resolveRecommendations(problems) {
  const byCode = new Map(problems.map((problem) => [problem.code, problem]));
  return recommendations.map((recommendation) => {
    const problem = byCode.get(recommendation.code) || null;
    return { ...recommendation, problem, title: problem?.title || null };
  });
}
