/** nCr modulo 1e9+7: O(maxN + log MOD) preprocessing, O(1) per query. */
public class Combinations {
    public static final int MOD = 1_000_000_007; // Prime; require maxN < MOD.
    private final long[] fact, inverseFact;

    public Combinations(int maxN) {
        if (maxN < 0 || maxN >= MOD) throw new IllegalArgumentException();
        fact = new long[maxN + 1];
        inverseFact = new long[maxN + 1];
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) fact[i] = fact[i - 1] * i % MOD;
        inverseFact[maxN] = power(fact[maxN], MOD - 2);
        for (int i = maxN; i > 0; i--) inverseFact[i - 1] = inverseFact[i] * i % MOD;
    }
    private static long power(long a, int b) {
        long answer = 1;
        while (b > 0) {
            if ((b & 1) != 0) answer = answer * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return answer;
    }
    public long nCr(int n, int r) {
        if (n < 0 || n >= fact.length) throw new IllegalArgumentException("n outside precomputed range");
        if (r < 0 || r > n) return 0;
        return fact[n] * inverseFact[r] % MOD * inverseFact[n - r] % MOD;
    }
    public static void main(String[] args) {
        System.out.println(new Combinations(100).nCr(5, 2)); // 10
    }
}
