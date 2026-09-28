import java.util.*;

/** Connected undirected tree. O(n log n) build/space; O(log n) LCA/ancestor queries. */
public class BinaryLiftingLCA {
    private final int[][] up;
    private final int[] depth;
    public BinaryLiftingLCA(List<List<Integer>> tree, int root) {
        int n = tree.size();
        if (n == 0 || root < 0 || root >= n) throw new IllegalArgumentException();
        int levels = 32 - Integer.numberOfLeadingZeros(n);
        up = new int[levels][n]; depth = new int[n];
        Arrays.fill(depth, -1);
        Queue<Integer> queue = new ArrayDeque<>();
        depth[root] = 0; up[0][root] = root; queue.add(root);
        int visited = 0;
        while (!queue.isEmpty()) {
            int v = queue.remove(); visited++;
            for (int to : tree.get(v)) {
                if (to == up[0][v]) continue;
                if (depth[to] != -1) throw new IllegalArgumentException("Expected a tree");
                depth[to] = depth[v] + 1; up[0][to] = v; queue.add(to);
            }
        }
        if (visited != n) throw new IllegalArgumentException("Tree must be connected");
        for (int k = 1; k < levels; k++)
            for (int v = 0; v < n; v++) up[k][v] = up[k - 1][up[k - 1][v]];
    }
    // Returns -1 when k exceeds the vertex's depth.
    public int kthAncestor(int v, int k) {
        if (k < 0) throw new IllegalArgumentException();
        if (k > depth[v]) return -1;
        for (int bit = 0; k > 0; bit++, k >>= 1) if ((k & 1) != 0) v = up[bit][v];
        return v;
    }
    public int lca(int a, int b) {
        if (depth[a] < depth[b]) { int t = a; a = b; b = t; }
        a = kthAncestor(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = up.length - 1; k >= 0; k--)
            if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
        return up[0][a];
    }
    public boolean isAncestor(int ancestor, int v) {
        return depth[ancestor] <= depth[v] && kthAncestor(v, depth[v] - depth[ancestor]) == ancestor;
    }
    public int distance(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
    public static void main(String[] args) {
        List<List<Integer>> tree = Arrays.asList(Arrays.asList(1, 2), Arrays.asList(0, 3), Arrays.asList(0), Arrays.asList(1));
        BinaryLiftingLCA lca = new BinaryLiftingLCA(tree, 0);
        System.out.println(lca.lca(2, 3)); // 0
        System.out.println(lca.distance(2, 3)); // 3
    }
}
