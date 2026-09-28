import java.util.*;

/** BFS and iterative DFS: O(V+E) time, O(V) auxiliary space. */
public class GraphTraversal {
    public static List<List<Integer>> newGraph(int n) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        return graph;
    }
    // BFS finds shortest distances measured in number of edges. -1 = unreachable.
    public static int[] bfs(List<List<Integer>> graph, int source) {
        int[] distance = new int[graph.size()];
        Arrays.fill(distance, -1);
        Queue<Integer> queue = new ArrayDeque<>();
        distance[source] = 0; queue.add(source);
        while (!queue.isEmpty()) {
            int v = queue.remove();
            for (int to : graph.get(v)) if (distance[to] == -1) {
                distance[to] = distance[v] + 1; queue.add(to);
            }
        }
        return distance;
    }
    // Reachable vertices in a stack traversal; avoids recursion overflow on long chains.
    public static List<Integer> dfs(List<List<Integer>> graph, int source) {
        List<Integer> order = new ArrayList<>();
        boolean[] visited = new boolean[graph.size()];
        Deque<Integer> stack = new ArrayDeque<>();
        visited[source] = true; stack.push(source);
        while (!stack.isEmpty()) {
            int v = stack.pop(); order.add(v);
            for (int to : graph.get(v)) if (!visited[to]) {
                visited[to] = true; stack.push(to);
            }
        }
        return order;
    }
    public static void main(String[] args) {
        List<List<Integer>> graph = newGraph(4);
        graph.get(0).add(1); graph.get(1).add(0); // Add both directions for an undirected edge.
        graph.get(1).add(2); graph.get(2).add(1);
        System.out.println(Arrays.toString(bfs(graph, 0))); // [0, 1, 2, -1]
        System.out.println(dfs(graph, 0)); // [0, 1, 2]
    }
}
