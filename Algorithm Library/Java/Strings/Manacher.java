import java.util.*;

/** Odd/even palindrome radii in O(n) time and space. Works on UTF-16 chars. */
public class Manacher {
    // odd[i] includes the center: longest length is 2*odd[i]-1.
    public static int[] oddPalindromes(String s) {
        int n = s.length();
        int[] d = new int[n];
        for (int i = 0, left = 0, right = -1; i < n; i++) {
            int k = i > right ? 1 : Math.min(d[left + right - i], right - i + 1);
            while (i - k >= 0 && i + k < n && s.charAt(i - k) == s.charAt(i + k)) k++;
            d[i] = k;
            if (i + k - 1 > right) { left = i - k + 1; right = i + k - 1; }
        }
        return d;
    }
    // even[i] is centered between i-1 and i: longest length is 2*even[i].
    public static int[] evenPalindromes(String s) {
        int n = s.length();
        int[] d = new int[n];
        for (int i = 0, left = 0, right = -1; i < n; i++) {
            int k = i > right ? 0 : Math.min(d[left + right - i + 1], right - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s.charAt(i - k - 1) == s.charAt(i + k)) k++;
            d[i] = k;
            if (i + k - 1 > right) { left = i - k; right = i + k - 1; }
        }
        return d;
    }
    public static void main(String[] args) {
        System.out.println(Arrays.toString(oddPalindromes("ababa"))); // [1, 2, 3, 2, 1]
        System.out.println(Arrays.toString(evenPalindromes("abba"))); // [0, 0, 2, 0]
    }
}
