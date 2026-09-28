import java.util.*;

/** Precompute primes, then factor into prime -> exponent using trial division. */
public class PrimeFactorization {
    private final int limit;
    private final List<Integer> primes = new ArrayList<>();

    // O(limit log log limit) time, O(limit) temporary space.
    public PrimeFactorization(int limit) {
        if (limit < 1) throw new IllegalArgumentException();
        this.limit = limit;
        boolean[] composite = new boolean[limit + 1];
        for (int p = 2; p <= limit; p++) {
            if (!composite[p]) {
                primes.add(p);
                for (long j = (long) p * p; j <= limit; j += p) composite[(int) j] = true;
            }
        }
    }
    // Requires floor(sqrt(n)) <= limit. Worst case O(pi(sqrt(n)) + log n).
    public Map<Long, Integer> factorize(long n) {
        long next = (long) limit + 1;
        if (n < 1 || n / next >= next)
            throw new IllegalArgumentException("Need positive n and primes through sqrt(n)");
        Map<Long, Integer> result = new LinkedHashMap<>();
        for (int p : primes) {
            if (p > n / p) break;
            int exponent = 0;
            while (n % p == 0) { n /= p; exponent++; }
            if (exponent > 0) result.put((long) p, exponent);
        }
        if (n > 1) result.put(n, 1);
        return result;
    }
    public static void main(String[] args) {
        System.out.println(new PrimeFactorization(100).factorize(360)); // {2=3, 3=2, 5=1}
    }
}
