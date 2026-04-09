import java.io.*;
import java.util.*;

public class Main {

    // ── Constants ───────────────────────────────────────────────
    static final boolean DEBUG = System.getProperty("cicada") != null;
    static final long INF = (long) 2e18;
    static final long MOD = (long) 1e9 + 7;

    // ── Fast I/O ─────────────────────────────────────────────────
    static BufferedReader br = new BufferedReader(
        new InputStreamReader(System.in)
    );
    static PrintWriter out = new PrintWriter(
        new BufferedWriter(new OutputStreamWriter(System.out))
    );
    static StringTokenizer st;

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(
            br.readLine()
        );
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static String nextLine() throws IOException {
        return br.readLine();
    }

    // ── Debug (goes to stderr, never affects output) ──────────────
    static void debug(Object... args) {
        if (DEBUG) System.err.println(Arrays.deepToString(args));
    }

    // ── Solve ─────────────────────────────────────────────────────
    static void solve() throws IOException {
        // your logic here
    }

    // ── Main ──────────────────────────────────────────────────────
    public static void main(String[] args) throws IOException {
        int t = nextInt();
        while (t-- > 0) {
            solve();
        }
        out.flush();
    }
}
