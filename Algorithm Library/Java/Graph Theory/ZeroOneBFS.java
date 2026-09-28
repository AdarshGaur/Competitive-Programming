import java.util.*;

/** 0-1 BFS: O(V+E) time/space, directed edges with weight exactly 0 or 1. */
public class ZeroOneBFS {
    public static class Edge {
        public final int to, weight;
        public Edge(int to, int weight) {
            if (weight != 0 && weight != 1) throw new IllegalArgumentException();
            this.to = to; this.weight = weight;
        }
    }
    public static int[] shortestPaths(List<List<Edge>> graph, int source) {
        int[] distance = new int[graph.size()];
        boolean[] settled = new boolean[graph.size()];
        Arrays.fill(distance, Integer.MAX_VALUE);
        Deque<Integer> deque = new ArrayDeque<>();
        distance[source] = 0; deque.addFirst(source);
        while (!deque.isEmpty()) {
            int v = deque.removeFirst();
            if (settled[v]) continue;
            settled[v] = true;
            for (Edge e : graph.get(v)) {
                if (distance[v] + e.weight < distance[e.to]) {
                    distance[e.to] = distance[v] + e.weight;
                    if (e.weight == 0) deque.addFirst(e.to);
                    else deque.addLast(e.to);
                }
            }
        }
        return distance; // Integer.MAX_VALUE means unreachable.
    }
    public static void main(String[] args) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < 3; i++) graph.add(new ArrayList<>());
        graph.get(0).add(new Edge(1, 1)); graph.get(0).add(new Edge(2, 0));
        graph.get(2).add(new Edge(1, 0));
        System.out.println(Arrays.toString(shortestPaths(graph, 0))); // [0, 0, 0]
    }
}
