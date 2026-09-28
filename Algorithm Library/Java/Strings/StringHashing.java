/** Double polynomial hashing: O(n) construction/space, O(1) substring hash.
 * Equal hashes are probabilistic evidence, not proof of equal strings.
 */
public class StringHashing {
    private static final long MOD1 = 1_000_000_007, MOD2 = 1_000_000_009, BASE = 911382323;
    private final long[] h1, h2, p1, p2;
    public StringHashing(String s) {
        int n = s.length();
        h1 = new long[n + 1]; h2 = new long[n + 1];
        p1 = new long[n + 1]; p2 = new long[n + 1]; p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            long c = s.charAt(i) + 1L;
            h1[i + 1] = (h1[i] * BASE + c) % MOD1;
            h2[i + 1] = (h2[i] * BASE + c) % MOD2;
            p1[i + 1] = p1[i] * BASE % MOD1; p2[i + 1] = p2[i] * BASE % MOD2;
        }
    }
    // [left, right); both residues packed into a long, so == compares the pair.
    // When comparing substrings, compare their lengths as well.
    public long hash(int left, int right) {
        if (left < 0 || left > right || right >= h1.length) throw new IndexOutOfBoundsException();
        int length = right - left;
        long a = (h1[right] - h1[left] * p1[length] % MOD1 + MOD1) % MOD1;
        long b = (h2[right] - h2[left] * p2[length] % MOD2 + MOD2) % MOD2;
        return (a << 32) | b;
    }
    public static void main(String[] args) {
        StringHashing h = new StringHashing("abcabc");
        System.out.println(h.hash(0, 3) == h.hash(3, 6)); // true
    }
}
