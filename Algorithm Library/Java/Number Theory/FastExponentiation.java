/** Binary exponentiation: O(log exponent) time, O(1) space. */
public class FastExponentiation {
    // Positive int modulus keeps multiplication of two residues safe in long.
    public static long modPow(long base, long exponent, int modulus) {
        if (exponent < 0 || modulus <= 0) throw new IllegalArgumentException();
        base = Math.floorMod(base, (long) modulus);
        long result = 1 % modulus;
        while (exponent > 0) {
            if ((exponent & 1) != 0) result = result * base % modulus;
            base = base * base % modulus;
            exponent >>= 1;
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(modPow(2, 10, 1_000_000_007)); // 1024
    }
}
