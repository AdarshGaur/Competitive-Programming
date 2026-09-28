import java.util.*;

/** Two common O(n) time, O(1) auxiliary space patterns. */
public class TwoPointers {
    // Requires ascending sorted input. Returns two distinct indices, or {-1, -1}.
    public static int[] pairWithSum(int[] sorted, long target) {
        int left = 0, right = sorted.length - 1;
        while (left < right) {
            long sum = (long) sorted[left] + sorted[right];
            if (sum == target) return new int[]{left, right};
            if (sum < target) left++; else right--;
        }
        return new int[]{-1, -1};
    }
    // NONNEGATIVE values only. Negative numbers invalidate this sliding window.
    public static int longestSumAtMost(int[] a, long limit) {
        for (int value : a) if (value < 0) throw new IllegalArgumentException("Need nonnegative values");
        if (limit < 0) return 0;
        long sum = 0;
        int left = 0, best = 0;
        for (int right = 0; right < a.length; right++) {
            sum += a[right];
            while (left <= right && sum > limit) sum -= a[left++];
            best = Math.max(best, right - left + 1);
        }
        return best;
    }
    public static void main(String[] args) {
        System.out.println(Arrays.toString(pairWithSum(new int[]{1, 2, 4, 8}, 6))); // [1, 2]
        System.out.println(longestSumAtMost(new int[]{1, 2, 1, 4}, 4)); // 3
    }
}
