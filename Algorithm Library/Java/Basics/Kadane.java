/** Maximum NONEMPTY subarray sum: O(n) time, O(1) space; sums must fit in long. */
public class Kadane {
    public static long maxSubarraySum(int[] a) {
        if (a.length == 0) throw new IllegalArgumentException("Need a nonempty array");
        long endingHere = a[0], best = a[0];
        for (int i = 1; i < a.length; i++) {
            endingHere = Math.max(a[i], endingHere + a[i]);
            best = Math.max(best, endingHere);
        }
        return best; // For all-negative input, returns the largest element.
    }
    public static void main(String[] args) {
        System.out.println(maxSubarraySum(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4})); // 6
    }
}
