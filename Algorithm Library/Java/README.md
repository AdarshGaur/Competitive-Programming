# Java algorithm library

Java versions of all 20 existing C++ files, plus beginner templates. The C++ files remain in their original locations. Each algorithm file is self-contained, uses only the Java standard library, and has a `main` method with a small example and expected output in comments. The source uses Java 8-compatible syntax and APIs.

## Getting started

Start with [Basics/Main.java](Basics/Main.java): it reads `n`, reads `n` integers, and prints their sum using buffered input/output. From the repository root, with a JDK installed:

```sh
mkdir -p /tmp/cp-java-demo
javac -d /tmp/cp-java-demo 'Algorithm Library/Java/Basics/Main.java'
printf '5\n1 2 3 4 5\n' | java -cp /tmp/cp-java-demo Main
# Output: 15
```

To run another example:

```sh
javac -d /tmp/cp-java-demo 'Algorithm Library/Java/Structures/FenwickTree.java'
java -cp /tmp/cp-java-demo FenwickTree
# Output: 11
```

The folders organize the files; these examples have **no package declarations**. The public class name matches the filename. Compiling with `-d` keeps generated `.class` files out of the source folders.

For an online judge, submit a file named `Main.java` with `public class Main` and `public static void main(String[] args)`. Replace the template's example logic with your solution. To reuse a data structure, copy its imports and put its class inside `Main` as a `static` nested class (for example, `static class DisjointSetUnion`), omitting its demo `main`. Alternatively, add it after `Main` as a non-public top-level class. Copy standalone methods into `Main` when that is simpler. Online judges usually expect all needed code in that one submission file.

## Suggested learning order

1. [Fast input/output and the submission template](Basics/Main.java), then [collections and strings](Basics/CollectionsDemo.java).
2. [Sorting, binary search, lower/upper bounds](Basics/SortingAndSearching.java).
3. [Prefix sums and difference arrays](Basics/PrefixSums.java), [two pointers and sliding windows](Basics/TwoPointers.java), and [Kadane's maximum subarray](Basics/Kadane.java).
4. [GCD/LCM](Basics/GcdLcm.java), [modular exponentiation](Number%20Theory/FastExponentiation.java), and [sieving primes](Number%20Theory/Sieve.java).
5. [BFS and iterative DFS](Basics/GraphTraversal.java), then the weighted shortest-path algorithms below.
6. [Coin change, 0/1 knapsack, and longest increasing subsequence](Basics/DynamicProgramming.java).
7. The data structures, LCA, and string algorithms below. [KMP](Strings/KMP.java) is an exact pattern-matching example to learn before using probabilistic string hashes.

## C++ to Java essentials

| C++ | Java | Notes |
| --- | --- | --- |
| `int`, `long long` | `int`, `long` | Signed 32-bit and 64-bit. Use `long` for sums, weights, products. |
| `vector<int>` | `int[]` or `ArrayList<Integer>` | Arrays have fixed length; lists grow. |
| `a.size()` | `a.length`, `list.size()`, `s.length()` | Arrays, collections, strings have different accessors. |
| `vector<vector<int>>` | `List<List<Integer>>` | Initialize each inner list separately. |
| `pair<int, int>` | Small class or `int[]` | Name fields for clarity; use `long` fields for large weights. |
| `unordered_map`, `unordered_set` | `HashMap`, `HashSet` | Expected O(1) operations; iteration order is unspecified. |
| `map`, `set` | `TreeMap`, `TreeSet` | O(log n); `ceiling`, `floor`, `higher`, `lower` support ordered lookup. |
| PBDS ordered set | [OrderedSet](OrderedSet.java) | Adds O(log n) rank and k-th-smallest queries; `TreeSet` does not provide these. |
| `queue`, `deque`, `stack` | `ArrayDeque` | `addLast/removeFirst` for a queue, `push/pop` for a stack. |
| `priority_queue` | `PriorityQueue` | Java defaults to a **min-heap**. Use `Comparator.reverseOrder()` for a max-heap. |
| `sort` | `Arrays.sort`, `Collections.sort` | Custom comparators need objects, not primitive `int[]`. |
| `lower_bound`, `upper_bound` | [Explicit binary searches](Basics/SortingAndSearching.java) | Return first `>=` and first `>` positions, including array length. |
| `string` | `String` / `StringBuilder` | `String` is immutable; use `StringBuilder` for repeated appends. |

- Java generics use wrapper types (`Integer`, `Long`), not primitives. Prefer primitive arrays for large numeric tables to reduce memory and allocation overhead.
- Java passes arguments by value. Array/object references are copied, so methods can mutate the referenced array. Use `clone()` when you need a separate primitive array. A two-dimensional array needs each row cloned for a deep copy.
- Write `1L * a * b`, not `(long) (a * b)`: the latter converts **after** an `int` multiplication may have overflowed. Integer division truncates; use `a / (double) b` for a fractional result.
- Compare string contents with `s.equals(t)`, not `s == t`. For nullable objects, use `Objects.equals(s, t)`.
- Use `Integer.compare(a, b)` or `Long.compare(a, b)` in comparators; subtraction can overflow.
- `list.remove(2)` removes index 2. `list.remove(Integer.valueOf(2))` removes the value 2.
- Numeric arrays start with zeroes, boolean arrays with `false`, reference arrays with `null`. Use `Arrays.fill` for other defaults.
- Java remainder can be negative. Use `Math.floorMod(value, modulus)` for a nonnegative modular residue.
- The fast scanner assumes ASCII whitespace-delimited contest input. `next()` returns `null` at EOF; numeric reads throw at EOF or on invalid/out-of-range numbers. It is not a Unicode text reader. `Scanner` is convenient for small inputs but has more overhead.
- Graph traversal and LCA use iterative processing to handle deep graphs without depending on the Java call stack. The balanced tree and segment tree recurse only to logarithmic depth.

## Indexing and numeric contracts

- Vertices and public indices are **zero-based**. Subtract one when reading one-based problem input.
- Range operations use **`[left, right)`**, including `left` and excluding `right`. For an inclusive input interval `[l, r]`, query `[l, r + 1)`. For a one-based inclusive interval, query `[l - 1, r)`.
- Empty ranges return zero for sums, do nothing for assignment, and have hash zero. Sparse-table queries require a nonempty range. Kadane requires a nonempty array.
- Graph adjacency lists represent directed edges. Add both directions for an undirected graph. LCA expects a connected, simple undirected tree.
- Dijkstra requires nonnegative weights; 0-1 BFS requires weights exactly zero or one. Their unreachable sentinels are `Dijkstra.INF` and `Integer.MAX_VALUE`, respectively. Basic BFS uses `-1`.
- Dijkstra's finite path sums must be below `INF`. Bellman-Ford requires `n * max(abs(weight)) < INF`. Floyd-Warshall expects edge weights and finite shortest distances strictly between `-INF` and `INF`; initialize its matrix with `newDistances`, then add edges using `Math.min` to handle parallel edges. All these `INF` constants are `Long.MAX_VALUE / 4`.
- Bellman-Ford reports only negative cycles reachable from the source. When its flag is true, do not use the returned arrays as valid shortest paths. For Floyd-Warshall, `isNegativelyUnbounded` identifies pairs that can travel through a negative cycle; their stored matrix values are not finite shortest distances.
- Ordinary sums, DP totals, and range-assignment products must fit in `long`. `GcdLcm` explicitly rejects `Long.MIN_VALUE` and throws if LCM overflows. Use `BigInteger` when the problem requires arbitrary precision.
- Modular exponentiation accepts a positive `int` modulus so residue multiplication fits in `long`. Combinations use the fixed prime `1_000_000_007`, with `0 <= maxN < MOD` and queries within the precomputed range.
- Trial factorization accepts positive values; 1 has an empty factorization. The precomputed-primes version requires primes through `floor(sqrt(n))` and checks the bound. Large `long` inputs can be too slow for trial division.
- Trie supports lowercase `a`–`z` and the empty string. Other string algorithms operate on Java UTF-16 `char` positions. Both Manacher versions accept separator-like characters in the input.
- Hash equality can collide, even with two moduli. Compare substring lengths too; use KMP or direct comparison when exact equality is required.

## Coverage of the existing library

C++ paths below are relative to the original `Algorithm Library` directory. Java links are relative to this guide. `n` means number of elements; `V` and `E` mean vertices and edges.

| Existing C++ file | Java counterpart | Operations / time |
| --- | --- | --- |
| `Ordered-set.cpp` | [OrderedSet.java](OrderedSet.java) | AVL set: insert, erase, membership, rank, zero-based k-th **smallest**, all O(log n); unique `long` keys |
| `Structures/Disjoint_Set_Union.cpp` | [DisjointSetUnion.java](Structures/DisjointSetUnion.java) | Union/find, component count and size; O(alpha(n)) amortized |
| `Structures/Fenwick_Tree.cpp` | [FenwickTree.java](Structures/FenwickTree.java) | O(n log n) build; point addition and prefix/range sums O(log n) |
| `Structures/Sparse_Table.cpp` | [SparseTable.java](Structures/SparseTable.java) | O(n log n) build; idempotent query O(1), general associative query O(log n) |
| `Structures/Trie.cpp` | [Trie.java](Structures/Trie.java) | Insert, exact lookup, prefix lookup O(word length) |
| `Trees/sum-segment-tree.cpp` | [SumSegmentTree.java](Trees/SumSegmentTree.java) | O(n) build; point assignment, lazy range assignment, range sum O(log n) |
| `LCA/lca-binary_lifting.cpp` | [BinaryLiftingLCA.java](LCA/BinaryLiftingLCA.java) | O(n log n) build; LCA, k-th ancestor, ancestry, distance O(log n) |
| `Graph Theory/0_1-BFS.cpp` | [ZeroOneBFS.java](Graph%20Theory/ZeroOneBFS.java) | 0/1 shortest paths O(V + E) |
| `Graph Theory/Dijkstra's-algo.cpp` | [Dijkstra.java](Graph%20Theory/Dijkstra.java) | Nonnegative shortest paths and path reconstruction; lazy heap O((V + E) log(V + E)) |
| `Graph Theory/Bellman-ford.cpp` | [BellmanFord.java](Graph%20Theory/BellmanFord.java) | Negative edges, parents, reachable negative-cycle detection O(VE) |
| `Graph Theory/Floyd-Warshall.cpp` | [FloydWarshall.java](Graph%20Theory/FloydWarshall.java) | All-pairs shortest paths O(V^3) |
| `Graph Theory/Topological-sort.cpp` | [TopologicalSort.java](Graph%20Theory/TopologicalSort.java) | Kahn's algorithm O(V + E), returns `null` on a cycle |
| `Number Theory/Fast-exponentiation.cpp` | [FastExponentiation.java](Number%20Theory/FastExponentiation.java) | Modular power O(log exponent) |
| `Number Theory/Sieve.cpp` | [Sieve.java](Number%20Theory/Sieve.java) | Prime flags and prime list through inclusive limit, O(n log log n) |
| `Number Theory/simple-factorization.cpp` | [SimpleFactorization.java](Number%20Theory/SimpleFactorization.java) | Repeated prime factors by trial division O(sqrt(n)) |
| `Number Theory/factorization-with-pre_computed-primes.cpp` | [PrimeFactorization.java](Number%20Theory/PrimeFactorization.java) | Prime-exponent map; per query O(pi(sqrt(n)) + log n) worst case after sieving |
| `Number Theory/nCr.cpp` | [Combinations.java](Number%20Theory/Combinations.java) | Factorials/inverse factorials O(n + log MOD), nCr O(1) |
| `Strings/Hashing.cpp` | [StringHashing.java](Strings/StringHashing.java) | Double substring hashing: O(n) build, O(1) query |
| `Strings/Manacher's Algorihtm.cpp` | [Manacher.java](Strings/Manacher.java) | Odd/even palindrome radii O(n) |
| `Strings/Manacher's Algorithm (Simplified Implementation).cpp` | [ManacherSimplified.java](Strings/ManacherSimplified.java) | Transformed-string palindrome radii O(n) |

Implementation details intentionally differ where useful: the Java topological sort uses a queue and interprets `u -> v` as **u before v** (reverse dependency edges if needed); LCA uses iterative traversal; the segment tree uses lazy propagation for range assignment. The Java implementations correct algorithmic errors in the snippets without changing the C++ sources.

For either Manacher version, `odd[i]` includes the center and gives longest length `2 * odd[i] - 1`; `even[i]` is centered between `i - 1` and `i` and gives length `2 * even[i]`. Both arrays have exactly the input length. In a sparse table, use `query` only for idempotent operations such as min/max/gcd; use `queryAssociative` for sum. Fenwick `add` adds a delta; assigning a new value requires adding `newValue - oldValue`.

## Verification

Run from the repository root with Bash and JDK 9+ (the test runner uses `--release 8`):

```sh
bash 'Algorithm Library/Java/tests/run.sh'
```

The runner compiles every file with lint warnings treated as errors, runs deterministic regression tests and randomized comparisons with simple reference solutions, runs every standalone demo, and verifies the submission template's sample input/output. Compilation output goes into a temporary directory which is removed afterward. No build tool or external dependency is needed.

Tests cover empty/singleton inputs, duplicate set keys, negative and zero range assignments, unreachable vertices, negative cycles, arbitrary Manacher separator characters, full-range signed integer parsing, scanner buffer boundaries, and a 100,000-vertex chain for iterative graph/tree processing.
