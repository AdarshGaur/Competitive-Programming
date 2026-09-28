import java.util.*;

/** Trial division: O(sqrt(n)) time; returns repeated prime factors in order. */
public class SimpleFactorization {
    public static List<Long> factorize(long n) {
        if (n < 1) throw new IllegalArgumentException("n must be positive");
        List<Long> factors = new ArrayList<>();
        // Division instead of p*p avoids overflow. 1 has no prime factors.
        for (long p = 2; p <= n / p; p += (p == 2 ? 1 : 2)) {
            while (n % p == 0) {
                factors.add(p);
                n /= p;
            }
        }
        if (n > 1) factors.add(n);
        return factors;
    }
    public static void main(String[] args) {
        System.out.println(factorize(60)); // [2, 2, 3, 5]
    }
}
