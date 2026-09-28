/** Sum tree with point/range assignment. O(n) build, O(log n) operations, O(n) space. */
public class SumSegmentTree {
    private final int n;
    private final long[] tree, lazy;
    private final boolean[] pending;
    public SumSegmentTree(long[] values) {
        n = values.length;
        tree = new long[Math.max(1, 4 * n)];
        lazy = new long[tree.length];
        pending = new boolean[tree.length];
        if (n > 0) build(1, 0, n, values);
    }
    private void build(int v, int lo, int hi, long[] a) {
        if (hi - lo == 1) { tree[v] = a[lo]; return; }
        int mid = (lo + hi) >>> 1;
        build(v * 2, lo, mid, a); build(v * 2 + 1, mid, hi, a);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    private void apply(int v, int length, long value) {
        tree[v] = value * length;
        lazy[v] = value;
        pending[v] = true; // Separate flag: assignment to zero is valid.
    }
    private void push(int v, int lo, int hi) {
        if (!pending[v] || hi - lo == 1) return;
        int mid = (lo + hi) >>> 1;
        apply(v * 2, mid - lo, lazy[v]); apply(v * 2 + 1, hi - mid, lazy[v]);
        pending[v] = false;
    }
    private void check(int left, int right) {
        if (left < 0 || left > right || right > n) throw new IndexOutOfBoundsException();
    }
    public void set(int index, long value) {
        if (index < 0 || index >= n) throw new IndexOutOfBoundsException();
        assign(index, index + 1, value);
    }
    public void assign(int left, int right, long value) { // [left, right)
        check(left, right);
        if (left < right) assign(1, 0, n, left, right, value);
    }
    private void assign(int v, int lo, int hi, int left, int right, long value) {
        if (right <= lo || hi <= left) return;
        if (left <= lo && hi <= right) { apply(v, hi - lo, value); return; }
        push(v, lo, hi);
        int mid = (lo + hi) >>> 1;
        assign(v * 2, lo, mid, left, right, value);
        assign(v * 2 + 1, mid, hi, left, right, value);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    public long sum(int left, int right) { // [left, right)
        check(left, right);
        return left == right ? 0 : sum(1, 0, n, left, right);
    }
    private long sum(int v, int lo, int hi, int left, int right) {
        if (right <= lo || hi <= left) return 0;
        if (left <= lo && hi <= right) return tree[v];
        push(v, lo, hi);
        int mid = (lo + hi) >>> 1;
        return sum(v * 2, lo, mid, left, right) + sum(v * 2 + 1, mid, hi, left, right);
    }
    public static void main(String[] args) {
        SumSegmentTree tree = new SumSegmentTree(new long[]{1, 2, 3, 4});
        tree.assign(1, 3, 5);
        tree.set(0, 2);
        System.out.println(tree.sum(0, 4)); // 16
    }
}
