import java.util.*;

/** All-pairs shortest paths: O(V^3) time, O(V^2) space. */
public class FloydWarshall {
    public static final long INF = Long.MAX_VALUE / 4;
    public static long[][] newDistances(int n) {
        long[][] d = new long[n][n];
        for (int i = 0; i < n; i++) { Arrays.fill(d[i], INF); d[i][i] = 0; }
        return d;
    }
    // Initialize edges with d[u][v] = Math.min(d[u][v], weight), then call this.
    // Finite shortest distances must lie strictly between -INF and INF.
    public static long[][] shortestPaths(long[][] input) {
        int n = input.length;
        long[][] d = new long[n][];
        for (int i = 0; i < n; i++) d[i] = input[i].clone();
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (d[i][k] != INF && d[k][j] != INF)
                        d[i][j] = Math.min(d[i][j], Math.max(-INF, d[i][k] + d[k][j]));
        return d;
    }
    public static boolean hasNegativeCycle(long[][] distance) {
        for (int i = 0; i < distance.length; i++) if (distance[i][i] < 0) return true;
        return false;
    }
    // A pair has no finite shortest path if it can travel through a negative cycle.
    public static boolean isNegativelyUnbounded(long[][] d, int from, int to) {
        for (int k = 0; k < d.length; k++)
            if (d[from][k] != INF && d[k][k] < 0 && d[k][to] != INF) return true;
        return false;
    }
    public static void main(String[] args) {
        long[][] d = newDistances(3);
        d[0][1] = 4; d[1][2] = -2;
        System.out.println(shortestPaths(d)[0][2]); // 2
    }
}
