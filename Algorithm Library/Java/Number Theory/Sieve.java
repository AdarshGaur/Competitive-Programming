import java.util.*;

/** Primes through limit (inclusive): O(limit log log limit) time, O(limit) space. */
public class Sieve {
    public final boolean[] isPrime;
    public final List<Integer> primes = new ArrayList<>();

    public Sieve(int limit) {
        if (limit < 0) throw new IllegalArgumentException();
        isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        if (limit >= 1) isPrime[1] = false;
        for (int p = 2; p <= limit / p; p++) {
            if (isPrime[p]) {
                for (long multiple = (long) p * p; multiple <= limit; multiple += p)
                    isPrime[(int) multiple] = false;
            }
        }
        for (int p = 2; p <= limit; p++) if (isPrime[p]) primes.add(p);
    }
    public static void main(String[] args) {
        System.out.println(new Sieve(20).primes); // [2, 3, 5, 7, 11, 13, 17, 19]
    }
}
