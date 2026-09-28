import java.util.*;

/** O(n) build, O(1) sum on [left, right). Sums must fit in long. */
public class PrefixSums {
    private final long[] prefix;
    public PrefixSums(long[] a) {
        prefix = new long[a.length + 1];
        for (int i = 0; i < a.length; i++) prefix[i + 1] = prefix[i] + a[i];
    }
    public long sum(int left, int right) {
        if (left < 0 || left > right || right >= prefix.length) throw new IndexOutOfBoundsException();
        return prefix[right] - prefix[left];
    }
    /** Offline range additions: O(n + q). ranges[i] = {left, right}; end exclusive. */
    public static long[] rangeAdditions(int n, int[][] ranges, long[] deltas) {
        if (ranges.length != deltas.length) throw new IllegalArgumentException();
        long[] difference = new long[n + 1];
        for (int i = 0; i < ranges.length; i++) {
            int left = ranges[i][0], right = ranges[i][1];
            if (left < 0 || left > right || right > n) throw new IndexOutOfBoundsException();
            difference[left] += deltas[i]; difference[right] -= deltas[i];
        }
        long[] result = new long[n];
        long current = 0;
        for (int i = 0; i < n; i++) { current += difference[i]; result[i] = current; }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(new PrefixSums(new long[]{2, 4, 6}).sum(1, 3)); // 10
        System.out.println(Arrays.toString(rangeAdditions(4, new int[][]{{1, 3}}, new long[]{5}))); // [0, 5, 5, 0]
    }
}
