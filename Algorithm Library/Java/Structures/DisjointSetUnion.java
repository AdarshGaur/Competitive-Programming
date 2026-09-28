/** Union by size and path compression: O(alpha(n)) amortized per operation. */
public class DisjointSetUnion {
    private final int[] parent, size;
    private int components;
    public DisjointSetUnion(int n) {
        parent = new int[n];
        size = new int[n];
        components = n;
        for (int i = 0; i < n; i++) { parent[i] = i; size[i] = 1; }
    }
    public int find(int v) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
    public boolean union(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) { int t = a; a = b; b = t; }
        parent[b] = a;
        size[a] += size[b];
        components--;
        return true;
    }
    public int componentSize(int v) { return size[find(v)]; }
    public int components() { return components; }
    public static void main(String[] args) {
        DisjointSetUnion dsu = new DisjointSetUnion(4);
        dsu.union(0, 1);
        System.out.println(dsu.componentSize(0)); // 2
        System.out.println(dsu.components()); // 3
    }
}
