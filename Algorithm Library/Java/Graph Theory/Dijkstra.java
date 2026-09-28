import java.util.*;

/** Nonnegative weighted directed graph. O((V+E) log(V+E)) time with a lazy heap. */
public class Dijkstra {
    public static final long INF = Long.MAX_VALUE / 4;
    public static class Edge {
        public final int to;
        public final long weight;
        public Edge(int to, long weight) {
            if (weight < 0 || weight >= INF) throw new IllegalArgumentException();
            this.to = to; this.weight = weight;
        }
    }
    public static class Result {
        public final long[] distance;
        public final int[] parent;
        Result(long[] distance, int[] parent) { this.distance = distance; this.parent = parent; }
        public List<Integer> pathTo(int target) {
            List<Integer> path = new ArrayList<>();
            if (distance[target] == INF) return path;
            for (int v = target; v != -1; v = parent[v]) path.add(v);
            Collections.reverse(path);
            return path;
        }
    }
    public static Result shortestPaths(List<List<Edge>> graph, int source) {
        int n = graph.size();
        long[] dist = new long[n];
        int[] parent = new int[n];
        Arrays.fill(dist, INF); Arrays.fill(parent, -1);
        // Entries hold {distance, vertex}; compare without subtraction/overflow.
        PriorityQueue<long[]> queue = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        dist[source] = 0;
        queue.add(new long[]{0, source});
        while (!queue.isEmpty()) {
            long[] entry = queue.poll();
            int v = (int) entry[1];
            if (entry[0] != dist[v]) continue; // Ignore stale heap entries.
            for (Edge edge : graph.get(v)) {
                long candidate = dist[v] + edge.weight;
                if (candidate < dist[edge.to]) {
                    dist[edge.to] = candidate;
                    parent[edge.to] = v;
                    queue.add(new long[]{candidate, edge.to});
                }
            }
        }
        return new Result(dist, parent);
    }
    public static void main(String[] args) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < 3; i++) graph.add(new ArrayList<>());
        graph.get(0).add(new Edge(1, 4)); graph.get(1).add(new Edge(2, 2));
        Result result = shortestPaths(graph, 0);
        System.out.println(Arrays.toString(result.distance)); // [0, 4, 6]
        System.out.println(result.pathTo(2)); // [0, 1, 2]
    }
}
