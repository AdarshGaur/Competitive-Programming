import java.util.*;

/** Negative edges allowed. O(VE) time, O(V) auxiliary space. */
public class BellmanFord {
    public static final long INF = Long.MAX_VALUE / 4;
    public static class Edge {
        public final int from, to;
        public final long weight;
        public Edge(int from, int to, long weight) {
            this.from = from; this.to = to; this.weight = weight;
        }
    }
    public static class Result {
        public final long[] distance;
        public final int[] parent;
        public final boolean hasReachableNegativeCycle;
        Result(long[] d, int[] p, boolean cycle) {
            distance = d; parent = p; hasReachableNegativeCycle = cycle;
        }
    }
    // Keep n * max(abs(weight)) < INF. With a reachable negative cycle,
    // distances/parents are intermediate values, not valid shortest-path results.
    public static Result shortestPaths(int n, List<Edge> edges, int source) {
        long[] distance = new long[n];
        int[] parent = new int[n];
        Arrays.fill(distance, INF); Arrays.fill(parent, -1);
        distance[source] = 0;
        for (int pass = 1; pass <= n; pass++) {
            // Each pass uses paths with at most 'pass' edges, bounding arithmetic.
            long[] next = distance.clone();
            boolean changed = false;
            for (Edge e : edges) {
                if (distance[e.from] == INF) continue;
                long candidate = Math.addExact(distance[e.from], e.weight);
                if (candidate < next[e.to]) {
                    next[e.to] = candidate; parent[e.to] = e.from; changed = true;
                }
            }
            distance = next;
            if (!changed) return new Result(distance, parent, false);
            if (pass == n) return new Result(distance, parent, true);
        }
        return new Result(distance, parent, false);
    }
    public static void main(String[] args) {
        List<Edge> edges = Arrays.asList(new Edge(0, 1, 4), new Edge(1, 2, -2));
        Result result = shortestPaths(3, edges, 0);
        System.out.println(Arrays.toString(result.distance)); // [0, 4, 2]
        System.out.println(result.hasReachableNegativeCycle); // false
    }
}
