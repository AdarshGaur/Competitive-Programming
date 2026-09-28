/** 0-based public indices. O(n log n) build, O(log n) update/query, O(n) space. */
public final class FenwickTree {
    private final long[] bit;
    public FenwickTree(long[] values) {
        bit = new long[values.length + 1];
        for (int i = 0; i < values.length; i++) add(i, values[i]);
    }
    public void add(int index, long delta) {
        if (index < 0 || index >= bit.length - 1) throw new IndexOutOfBoundsException();
        for (int i = index + 1; i < bit.length; i += i & -i) bit[i] += delta;
    }
    // Sum on [0, end); prefixSum(0) is zero.
    public long prefixSum(int end) {
        if (end < 0 || end >= bit.length) throw new IndexOutOfBoundsException();
        long sum = 0;
        for (int i = end; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }
    public long sum(int left, int right) { // [left, right)
        if (left < 0 || left > right || right >= bit.length) throw new IndexOutOfBoundsException();
        return prefixSum(right) - prefixSum(left);
    }
    public static void main(String[] args) {
        FenwickTree tree = new FenwickTree(new long[]{1, 2, 3});
        tree.add(1, 5);
        System.out.println(tree.sum(0, 3)); // 11
    }
}
