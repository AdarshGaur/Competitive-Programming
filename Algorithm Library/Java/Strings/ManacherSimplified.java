import java.util.*;

/** Transformed-string Manacher: O(n) time/space, including arbitrary UTF-16 chars. */
public class ManacherSimplified {
    public final int[] odd, even;
    public ManacherSimplified(String s) {
        int n = s.length();
        // Integer sentinels cannot collide with input chars (unlike '#', '$', '^').
        int[] text = new int[2 * n + 3];
        text[0] = -2; text[text.length - 1] = -3;
        for (int i = 0; i <= n; i++) text[2 * i + 1] = -1;
        for (int i = 0; i < n; i++) text[2 * i + 2] = s.charAt(i);
        int[] radius = new int[text.length];
        for (int i = 1, center = 0, right = 0; i < text.length - 1; i++) {
            if (i < right) radius[i] = Math.min(right - i, radius[2 * center - i]);
            while (text[i - radius[i] - 1] == text[i + radius[i] + 1]) radius[i]++;
            if (i + radius[i] > right) { center = i; right = i + radius[i]; }
        }
        odd = new int[n]; even = new int[n];
        for (int i = 0; i < n; i++) {
            odd[i] = (radius[2 * i + 2] + 1) / 2;
            even[i] = radius[2 * i + 1] / 2;
        }
    }
    public static void main(String[] args) {
        ManacherSimplified result = new ManacherSimplified("abba");
        System.out.println(Arrays.toString(result.even)); // [0, 0, 2, 0]
    }
}
