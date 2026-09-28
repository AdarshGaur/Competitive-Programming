/** Euclid's algorithm: O(log(min(|a|, |b|))) time, O(1) space. */
public class GcdLcm {
    // Long.MIN_VALUE is excluded because its absolute value cannot fit in long.
    public static long gcd(long a, long b) {
        if (a == Long.MIN_VALUE || b == Long.MIN_VALUE) throw new IllegalArgumentException();
        a = Math.abs(a); b = Math.abs(b);
        while (b != 0) { long remainder = a % b; a = b; b = remainder; }
        return a; // gcd(0, 0) = 0 by convention.
    }
    public static long lcm(long a, long b) {
        long divisor = gcd(a, b);
        if (a == 0 || b == 0) return 0;
        // Divide first; throw ArithmeticException if the positive result overflows.
        return Math.multiplyExact(Math.abs(a) / divisor, Math.abs(b));
    }
    public static void main(String[] args) {
        System.out.println(gcd(18, 24)); // 6
        System.out.println(lcm(18, 24)); // 72
    }
}
