import java.util.*;

/** Kahn's algorithm: O(V+E) time, O(V) extra space. Edge u->v means u before v. */
public class TopologicalSort {
    // Returns null for a cycle; returns an empty array for an empty graph.
    public static int[] sort(List<List<Integer>> graph) {
        int n = graph.size();
        int[] indegree = new int[n], order = new int[n];
        for (List<Integer> edges : graph) for (int v : edges) indegree[v]++;
        Queue<Integer> queue = new ArrayDeque<>();
        for (int v = 0; v < n; v++) if (indegree[v] == 0) queue.add(v);
        int count = 0;
        while (!queue.isEmpty()) {
            int v = queue.remove(); order[count++] = v;
            for (int to : graph.get(v)) if (--indegree[to] == 0) queue.add(to);
        }
        return count == n ? order : null;
    }
    public static void main(String[] args) {
        List<List<Integer>> graph = Arrays.asList(Arrays.asList(1, 2), Arrays.asList(2), Collections.emptyList());
        System.out.println(Arrays.toString(sort(graph))); // [0, 1, 2]
    }
}
