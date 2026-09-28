import java.io.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.util.*;

/** Dependency-free regression tests, including randomized brute-force comparisons. */
public class LibraryTest {
    private static final Random RANDOM = new Random(20260916L);
    private static int checks;
    private static void check(boolean condition) {
        checks++;
        if (!condition) throw new AssertionError("Failed check " + checks);
    }
    private static void equal(long actual, long expected) { check(actual == expected); }
    private static void arrays(int[] actual, int[] expected) { check(Arrays.equals(actual, expected)); }
    private static void throwsException(Class<? extends Exception> type, Runnable action) {
        try { action.run(); } catch (Exception e) { check(type.isInstance(e)); return; }
        throw new AssertionError("Expected " + type.getSimpleName());
    }
    private static void numberTheory() {
        for (int limit = 0; limit < 100; limit++) {
            Sieve sieve = new Sieve(limit);
            for (int n = 0; n <= limit; n++) {
                boolean prime = n >= 2;
                for (int p = 2; p * p <= n; p++) if (n % p == 0) prime = false;
                check(sieve.isPrime[n] == prime);
                check(sieve.primes.contains(n) == prime);
            }
        }
        PrimeFactorization factorizer = new PrimeFactorization(100);
        for (int n = 1; n <= 1000; n++) {
            Map<Long, Integer> expected = new LinkedHashMap<>();
            long product = 1;
            for (long factor : SimpleFactorization.factorize(n)) {
                check(BigInteger.valueOf(factor).isProbablePrime(20));
                product *= factor;
                expected.put(factor, expected.getOrDefault(factor, 0) + 1);
            }
            equal(product, n);
            check(factorizer.factorize(n).equals(expected));
        }
        throwsException(IllegalArgumentException.class, () -> new PrimeFactorization(2).factorize(9));
        for (int trial = 0; trial < 300; trial++) {
            long base = RANDOM.nextLong();
            int power = RANDOM.nextInt(1000), modulus = RANDOM.nextInt(Integer.MAX_VALUE - 1) + 1;
            equal(FastExponentiation.modPow(base, power, modulus),
                    BigInteger.valueOf(base).modPow(BigInteger.valueOf(power), BigInteger.valueOf(modulus)).longValue());
        }
        equal(FastExponentiation.modPow(0, 0, 1), 0);
        Combinations combinations = new Combinations(100);
        long[][] pascal = new long[101][101];
        pascal[0][0] = 1;
        for (int n = 0; n <= 100; n++) {
            if (n > 0) {
                pascal[n][0] = 1;
                for (int r = 1; r <= n; r++) pascal[n][r] = (pascal[n - 1][r - 1] + pascal[n - 1][r]) % Combinations.MOD;
            }
            for (int r = 0; r <= n; r++) equal(combinations.nCr(n, r), pascal[n][r]);
            equal(combinations.nCr(n, -1), 0); equal(combinations.nCr(n, n + 1), 0);
        }
        equal(new Combinations(0).nCr(0, 0), 1);
        equal(GcdLcm.gcd(-18, 24), 6); equal(GcdLcm.gcd(0, 0), 0);
        equal(GcdLcm.lcm(-18, 24), 72); equal(GcdLcm.lcm(0, 0), 0);
        throwsException(ArithmeticException.class, () -> GcdLcm.lcm(Long.MAX_VALUE, 2));
    }
    private static void structures() {
        for (int n = 0; n <= 40; n++) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = RANDOM.nextInt(100) - 50;
            FenwickTree bit = new FenwickTree(a);
            SumSegmentTree tree = new SumSegmentTree(a);
            for (int trial = 0; trial < 200; trial++) {
                int left = RANDOM.nextInt(n + 1), right = RANDOM.nextInt(n + 1);
                if (left > right) { int t = left; left = right; right = t; }
                if (trial % 3 == 0) {
                    long value = RANDOM.nextInt(101) - 50;
                    tree.assign(left, right, value);
                    for (int i = left; i < right; i++) { bit.add(i, value - a[i]); a[i] = value; }
                } else if (trial % 3 == 1 && n > 0) {
                    int i = RANDOM.nextInt(n); long value = RANDOM.nextInt(101) - 50;
                    tree.set(i, value); bit.add(i, value - a[i]); a[i] = value;
                }
                long sum = 0;
                for (int i = left; i < right; i++) sum += a[i];
                equal(tree.sum(left, right), sum); equal(bit.sum(left, right), sum);
            }
            SparseTable min = new SparseTable(a, Math::min);
            SparseTable sum = new SparseTable(a, Long::sum);
            PrefixSums prefix = new PrefixSums(a);
            for (int l = 0; l < n; l++) {
                long expectedMin = Long.MAX_VALUE, expectedSum = 0;
                for (int r = l + 1; r <= n; r++) {
                    expectedMin = Math.min(expectedMin, a[r - 1]); expectedSum += a[r - 1];
                    equal(min.query(l, r), expectedMin); equal(sum.queryAssociative(l, r), expectedSum);
                    equal(prefix.sum(l, r), expectedSum);
                }
            }
        }
        FenwickTree empty = new FenwickTree(new long[0]);
        throwsException(IndexOutOfBoundsException.class, () -> empty.add(-1, 1));
        throwsException(IndexOutOfBoundsException.class, () -> empty.add(0, 1));
        OrderedSet ordered = new OrderedSet();
        TreeSet<Long> oracle = new TreeSet<>();
        for (int i = 0; i < 5000; i++) {
            long key = RANDOM.nextInt(1000) - 500;
            if (RANDOM.nextBoolean()) check(ordered.add(key) == oracle.add(key));
            else check(ordered.remove(key) == oracle.remove(key));
            equal(ordered.size(), oracle.size());
            equal(ordered.orderOfKey(key), oracle.headSet(key).size());
            check(ordered.contains(key) == oracle.contains(key));
            int k = 0;
            for (long value : oracle) equal(ordered.findByOrder(k++), value);
        }
        ordered.add(Long.MIN_VALUE); ordered.add(Long.MAX_VALUE);
        equal(ordered.findByOrder(0), Long.MIN_VALUE);
        equal(ordered.findByOrder(ordered.size() - 1), Long.MAX_VALUE);
        for (long value : new ArrayList<>(oracle)) ordered.remove(value);
        ordered.remove(Long.MIN_VALUE); ordered.remove(Long.MAX_VALUE);
        equal(ordered.size(), 0);
        throwsException(IndexOutOfBoundsException.class, () -> ordered.findByOrder(0));
        for (int i = 0; i < 10000; i++) ordered.add(i); // Adversarial sorted insertion.
        for (int i = 0; i < 10000; i++) { equal(ordered.findByOrder(0), i); ordered.remove(i); }
        DisjointSetUnion dsu = new DisjointSetUnion(20);
        int[] label = new int[20];
        for (int i = 0; i < 20; i++) label[i] = i;
        for (int trial = 0; trial < 100; trial++) {
            int a = RANDOM.nextInt(20), b = RANDOM.nextInt(20);
            check(dsu.union(a, b) == (label[a] != label[b]));
            int old = label[b], replacement = label[a];
            for (int i = 0; i < 20; i++) if (label[i] == old) label[i] = replacement;
            Set<Integer> labels = new HashSet<>();
            for (int i = 0; i < 20; i++) {
                labels.add(label[i]); int size = 0;
                for (int j = 0; j < 20; j++) if (label[i] == label[j]) size++;
                equal(dsu.componentSize(i), size);
            }
            equal(dsu.components(), labels.size());
        }
        Trie trie = new Trie();
        check(!trie.contains("")); check(trie.startsWith(""));
        trie.insert(""); trie.insert("java"); trie.insert("java");
        check(trie.contains("")); check(trie.contains("java"));
        check(!trie.contains("jav")); check(trie.startsWith("jav")); check(!trie.startsWith("x"));
        throwsException(IllegalArgumentException.class, () -> trie.insert("Java"));
    }
    private static void strings() {
        String alphabet = "ab#$^\u0000\uffff";
        for (int trial = 0; trial < 500; trial++) {
            int n = RANDOM.nextInt(30);
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) builder.append(alphabet.charAt(RANDOM.nextInt(alphabet.length())));
            String s = builder.toString();
            int[] odd = new int[n], even = new int[n];
            for (int i = 0; i < n; i++) {
                int k = 1;
                while (i - k >= 0 && i + k < n && s.charAt(i - k) == s.charAt(i + k)) k++;
                odd[i] = k; k = 0;
                while (i - k - 1 >= 0 && i + k < n && s.charAt(i - k - 1) == s.charAt(i + k)) k++;
                even[i] = k;
            }
            arrays(Manacher.oddPalindromes(s), odd); arrays(Manacher.evenPalindromes(s), even);
            ManacherSimplified simplified = new ManacherSimplified(s);
            arrays(simplified.odd, odd); arrays(simplified.even, even);
            StringHashing hashing = new StringHashing(s);
            for (int l = 0; l <= n; l++) for (int r = l; r <= n; r++)
                equal(hashing.hash(l, r), new StringHashing(s.substring(l, r)).hash(0, r - l));
            String pattern = trial % 2 == 0 ? s.substring(0, RANDOM.nextInt(n + 1)) : "ab";
            List<Integer> matches = new ArrayList<>();
            for (int i = 0; i + pattern.length() <= n; i++) if (s.startsWith(pattern, i)) matches.add(i);
            check(KMP.findAll(s, pattern).equals(matches));
        }
        check(KMP.findAll("aaaaa", "aa").equals(Arrays.asList(0, 1, 2, 3)));
    }
    private static void graphs() {
        for (int trial = 0; trial < 120; trial++) {
            int n = RANDOM.nextInt(8) + 1;
            List<List<Dijkstra.Edge>> weighted = new ArrayList<>();
            List<List<ZeroOneBFS.Edge>> binary = new ArrayList<>();
            List<BellmanFord.Edge> edges = new ArrayList<>();
            long[][] matrix = FloydWarshall.newDistances(n);
            for (int i = 0; i < n; i++) { weighted.add(new ArrayList<>()); binary.add(new ArrayList<>()); }
            for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) if (RANDOM.nextInt(4) == 0) {
                int weight = RANDOM.nextInt(2);
                weighted.get(a).add(new Dijkstra.Edge(b, weight));
                binary.get(a).add(new ZeroOneBFS.Edge(b, weight));
                edges.add(new BellmanFord.Edge(a, b, weight));
                matrix[a][b] = Math.min(matrix[a][b], weight);
            }
            long[][] all = FloydWarshall.shortestPaths(matrix);
            for (int source = 0; source < n; source++) {
                Dijkstra.Result dijkstra = Dijkstra.shortestPaths(weighted, source);
                BellmanFord.Result bf = BellmanFord.shortestPaths(n, edges, source);
                check(!bf.hasReachableNegativeCycle);
                int[] zeroOne = ZeroOneBFS.shortestPaths(binary, source);
                for (int target = 0; target < n; target++) {
                    equal(dijkstra.distance[target], all[source][target]); equal(bf.distance[target], all[source][target]);
                    equal(zeroOne[target] == Integer.MAX_VALUE ? FloydWarshall.INF : zeroOne[target], all[source][target]);
                    List<Integer> path = dijkstra.pathTo(target);
                    if (all[source][target] == FloydWarshall.INF) check(path.isEmpty());
                    else {
                        equal(path.get(0), source); equal(path.get(path.size() - 1), target);
                        long cost = 0;
                        for (int k = 1; k < path.size(); k++) cost += matrix[path.get(k - 1)][path.get(k)];
                        equal(cost, all[source][target]);
                    }
                }
            }
        }
        // Negative edges without cycles; Floyd and Bellman-Ford must agree.
        for (int trial = 0; trial < 100; trial++) {
            int n = 8;
            long[][] matrix = FloydWarshall.newDistances(n);
            List<BellmanFord.Edge> edges = new ArrayList<>();
            List<List<Integer>> dag = GraphTraversal.newGraph(n);
            for (int a = 0; a < n; a++) for (int b = a + 1; b < n; b++) if (RANDOM.nextBoolean()) {
                long weight = RANDOM.nextInt(21) - 10;
                matrix[a][b] = weight; edges.add(new BellmanFord.Edge(a, b, weight)); dag.get(a).add(b);
            }
            long[][] all = FloydWarshall.shortestPaths(matrix);
            for (int source = 0; source < n; source++) {
                BellmanFord.Result result = BellmanFord.shortestPaths(n, edges, source);
                check(!result.hasReachableNegativeCycle); check(Arrays.equals(result.distance, all[source]));
            }
            int[] order = TopologicalSort.sort(dag), position = new int[n];
            check(order != null);
            for (int i = 0; i < n; i++) position[order[i]] = i;
            for (int a = 0; a < n; a++) for (int b : dag.get(a)) check(position[a] < position[b]);
        }
        List<BellmanFord.Edge> cycle = Arrays.asList(new BellmanFord.Edge(1, 2, -2), new BellmanFord.Edge(2, 1, 1));
        check(!BellmanFord.shortestPaths(3, cycle, 0).hasReachableNegativeCycle);
        check(BellmanFord.shortestPaths(3, cycle, 1).hasReachableNegativeCycle);
        long[][] negative = FloydWarshall.newDistances(3); negative[1][2] = -2; negative[2][1] = 1;
        negative = FloydWarshall.shortestPaths(negative);
        check(FloydWarshall.hasNegativeCycle(negative));
        check(FloydWarshall.isNegativelyUnbounded(negative, 1, 2));
        check(!FloydWarshall.isNegativelyUnbounded(negative, 0, 2));
        check(TopologicalSort.sort(Arrays.asList(Arrays.asList(1), Arrays.asList(0))) == null);
        check(TopologicalSort.sort(Arrays.asList(Arrays.asList(0))) == null);
        equal(TopologicalSort.sort(GraphTraversal.newGraph(0)).length, 0);
        for (int trial = 0; trial < 50; trial++) {
            int n = RANDOM.nextInt(50) + 1;
            List<List<Integer>> tree = GraphTraversal.newGraph(n);
            int[] parent = new int[n], depth = new int[n];
            for (int v = 1; v < n; v++) {
                parent[v] = RANDOM.nextInt(v); depth[v] = depth[parent[v]] + 1;
                tree.get(v).add(parent[v]); tree.get(parent[v]).add(v);
            }
            BinaryLiftingLCA lca = new BinaryLiftingLCA(tree, 0);
            arrays(GraphTraversal.bfs(tree, 0), depth);
            equal(new HashSet<>(GraphTraversal.dfs(tree, 0)).size(), n);
            for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) {
                int x = a, y = b;
                while (depth[x] > depth[y]) x = parent[x];
                while (depth[y] > depth[x]) y = parent[y];
                while (x != y) { x = parent[x]; y = parent[y]; }
                equal(lca.lca(a, b), x); equal(lca.distance(a, b), depth[a] + depth[b] - 2 * depth[x]);
                check(lca.isAncestor(a, b) == (x == a));
            }
            for (int v = 0; v < n; v++) {
                int expected = v;
                for (int k = 0; k <= depth[v]; k++) { equal(lca.kthAncestor(v, k), expected); expected = parent[expected]; }
                equal(lca.kthAncestor(v, depth[v] + 1), -1);
            }
            // A different root must preserve undirected tree distances.
            BinaryLiftingLCA rerooted = new BinaryLiftingLCA(tree, n - 1);
            for (int v = 0; v < n; v++) equal(rerooted.distance(0, v), depth[v]);
        }
        List<List<Integer>> chain = GraphTraversal.newGraph(100000);
        for (int v = 1; v < chain.size(); v++) { chain.get(v - 1).add(v); chain.get(v).add(v - 1); }
        equal(new BinaryLiftingLCA(chain, 0).lca(50000, 99999), 50000);
        equal(GraphTraversal.dfs(chain, 0).size(), 100000);
        arrays(GraphTraversal.bfs(GraphTraversal.newGraph(3), 0), new int[]{0, -1, -1});
    }
    private static void basics() throws IOException {
        for (int trial = 0; trial < 300; trial++) {
            int n = RANDOM.nextInt(20); int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = RANDOM.nextInt(11) - 5;
            int[] sorted = a.clone(); Arrays.sort(sorted);
            for (int target = -7; target <= 7; target++) {
                int lower = 0, upper = 0;
                while (lower < n && sorted[lower] < target) lower++;
                while (upper < n && sorted[upper] <= target) upper++;
                equal(SortingAndSearching.lowerBound(sorted, target), lower);
                equal(SortingAndSearching.upperBound(sorted, target), upper);
                equal(SortingAndSearching.binarySearch(sorted, target), lower < upper ? lower : -1);
                boolean pair = false;
                for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (sorted[i] + sorted[j] == target) pair = true;
                int[] result = TwoPointers.pairWithSum(sorted, target);
                check((result[0] != -1) == pair);
                if (pair) { check(result[0] < result[1]); equal(sorted[result[0]] + sorted[result[1]], target); }
            }
            if (n > 0) {
                long max = Long.MIN_VALUE;
                for (int i = 0; i < n; i++) {
                    long sum = 0;
                    for (int j = i; j < n; j++) { sum += a[j]; max = Math.max(max, sum); }
                }
                equal(Kadane.maxSubarraySum(a), max);
            }
            int[] dp = new int[n]; int best = 0;
            for (int i = 0; i < n; i++) {
                dp[i] = 1;
                for (int j = 0; j < i; j++) if (a[j] < a[i]) dp[i] = Math.max(dp[i], dp[j] + 1);
                best = Math.max(best, dp[i]);
            }
            equal(DynamicProgramming.lisLength(a), best);
            for (int i = 0; i < n; i++) a[i] = Math.abs(a[i]);
            int limit = RANDOM.nextInt(20), longest = 0;
            for (int i = 0; i < n; i++) {
                long sum = 0;
                for (int j = i; j < n; j++) { sum += a[j]; if (sum <= limit) longest = Math.max(longest, j - i + 1); }
            }
            equal(TwoPointers.longestSumAtMost(a, limit), longest);
            int items = RANDOM.nextInt(10), capacity = RANDOM.nextInt(15);
            int[] weights = new int[items]; long[] values = new long[items];
            for (int i = 0; i < items; i++) { weights[i] = RANDOM.nextInt(6); values[i] = RANDOM.nextInt(21) - 5; }
            long optimum = 0;
            for (int mask = 0; mask < (1 << items); mask++) {
                int weight = 0; long value = 0;
                for (int i = 0; i < items; i++) if ((mask & (1 << i)) != 0) { weight += weights[i]; value += values[i]; }
                if (weight <= capacity) optimum = Math.max(optimum, value);
            }
            equal(DynamicProgramming.knapsack(weights, values, capacity), optimum);
        }
        for (int amount = 0; amount < 60; amount++) {
            int best = Integer.MAX_VALUE;
            for (int a = 0; a * 3 <= amount; a++) for (int b = 0; a * 3 + b * 5 <= amount; b++)
                if (a * 3 + b * 5 == amount) best = Math.min(best, a + b);
            equal(DynamicProgramming.minCoins(new int[]{3, 5}, amount), best == Integer.MAX_VALUE ? -1 : best);
        }
        check(Arrays.equals(PrefixSums.rangeAdditions(4, new int[][]{{0, 3}, {1, 4}, {2, 2}}, new long[]{2, -1, 9}), new long[]{2, 1, 1, -1}));
        String input = " \n\t" + Long.MIN_VALUE + " " + Long.MAX_VALUE + " +0 -42 word";
        Main.FastScanner scanner = new Main.FastScanner(new ByteArrayInputStream(input.getBytes(StandardCharsets.US_ASCII)));
        equal(scanner.nextLong(), Long.MIN_VALUE); equal(scanner.nextLong(), Long.MAX_VALUE);
        equal(scanner.nextInt(), 0); equal(scanner.nextInt(), -42);
        check("word".equals(scanner.next())); check(scanner.next() == null);
        try { scanner.nextLong(); throw new AssertionError("Expected EOF"); } catch (EOFException expected) { checks++; }
        for (String bad : new String[]{"9223372036854775808", "-9223372036854775809", "-", "a"}) {
            Main.FastScanner invalid = new Main.FastScanner(new ByteArrayInputStream(bad.getBytes(StandardCharsets.US_ASCII)));
            try { invalid.nextLong(); throw new AssertionError("Expected invalid integer"); }
            catch (NumberFormatException expected) { checks++; }
        }
        // Cross the scanner's buffer boundary.
        StringBuilder large = new StringBuilder();
        for (int i = 0; i < 30000; i++) large.append(i).append(' ');
        scanner = new Main.FastScanner(new ByteArrayInputStream(large.toString().getBytes(StandardCharsets.US_ASCII)));
        for (int i = 0; i < 30000; i++) equal(scanner.nextInt(), i);
    }
    public static void main(String[] args) throws IOException {
        numberTheory(); structures(); strings(); graphs(); basics();
        System.out.println("Passed " + checks + " checks.");
    }
}
