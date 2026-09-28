import java.util.*;

/** Introductory DP: store answers to smaller subproblems and reuse them. */
public class DynamicProgramming {
    // Minimum number of coins with unlimited reuse. O(amount * coins.length), O(amount).
    // dp[sum] = minimum over dp[sum - coin] + 1. -1 means impossible.
    public static int minCoins(int[] coins, int amount) {
        if (amount < 0 || amount == Integer.MAX_VALUE) throw new IllegalArgumentException();
        for (int coin : coins) if (coin <= 0) throw new IllegalArgumentException();
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); dp[0] = 0;
        for (int sum = 1; sum <= amount; sum++)
            for (int coin : coins) if (coin <= sum) dp[sum] = Math.min(dp[sum], dp[sum - coin] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
    // 0/1 knapsack: each item at most once; may take no items. O(n*capacity), O(capacity).
    public static long knapsack(int[] weights, long[] values, int capacity) {
        if (weights.length != values.length || capacity < 0) throw new IllegalArgumentException();
        long[] dp = new long[capacity + 1];
        for (int i = 0; i < weights.length; i++) {
            if (weights[i] < 0) throw new IllegalArgumentException();
            // Descend so the same item is not reused in this iteration.
            for (int c = capacity; c >= weights[i]; c--)
                dp[c] = Math.max(dp[c], dp[c - weights[i]] + values[i]);
        }
        return dp[capacity];
    }
    // Strictly increasing subsequence length. tails[k] is the smallest tail at length k+1.
    // O(n log n) time, O(n) space.
    public static int lisLength(int[] a) {
        int[] tails = new int[a.length];
        int length = 0;
        for (int value : a) {
            int left = 0, right = length;
            while (left < right) {
                int mid = (left + right) >>> 1;
                if (tails[mid] < value) left = mid + 1; else right = mid;
            }
            tails[left] = value;
            if (left == length) length++;
        }
        return length;
    }
    public static void main(String[] args) {
        System.out.println(minCoins(new int[]{1, 3, 4}, 6)); // 2
        System.out.println(knapsack(new int[]{2, 3, 4}, new long[]{4, 5, 7}, 5)); // 9
        System.out.println(lisLength(new int[]{3, 1, 2, 2, 4})); // 3
    }
}
