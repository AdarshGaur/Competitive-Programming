import java.util.*;

/** Exact string matching with the prefix function: O(text + pattern) time/space. */
public class KMP {
    public static int[] prefixFunction(String s) {
        int[] pi = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            int j = pi[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) j = pi[j - 1];
            if (s.charAt(i) == s.charAt(j)) j++;
            pi[i] = j;
        }
        return pi;
    }
    // Returns zero-based starting indices, including overlapping matches.
    // Empty pattern matches every boundary: 0 through text.length().
    public static List<Integer> findAll(String text, String pattern) {
        List<Integer> positions = new ArrayList<>();
        if (pattern.isEmpty()) {
            for (int i = 0; i <= text.length(); i++) positions.add(i);
            return positions;
        }
        int[] pi = prefixFunction(pattern);
        for (int i = 0, j = 0; i < text.length(); i++) {
            while (j > 0 && text.charAt(i) != pattern.charAt(j)) j = pi[j - 1];
            if (text.charAt(i) == pattern.charAt(j)) j++;
            if (j == pattern.length()) { positions.add(i - j + 1); j = pi[j - 1]; }
        }
        return positions;
    }
    public static void main(String[] args) {
        System.out.println(findAll("ababa", "aba")); // [0, 2]
    }
}
