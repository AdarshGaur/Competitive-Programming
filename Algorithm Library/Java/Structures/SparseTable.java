import java.util.function.LongBinaryOperator;

/** Immutable range queries: O(n log n) construction and space. */
public class SparseTable {
    private final long[][] table;
    private final LongBinaryOperator operation;
    private final int n;
    // operation must be associative (e.g. min, max, gcd, sum).
    public SparseTable(long[] a, LongBinaryOperator operation) {
        n = a.length;
        this.operation = operation;
        int levels = n == 0 ? 0 : 32 - Integer.numberOfLeadingZeros(n);
        table = new long[levels][];
        if (n == 0) return;
        table[0] = a.clone();
        for (int k = 1; k < levels; k++) {
            table[k] = new long[n - (1 << k) + 1];
            for (int i = 0; i < table[k].length; i++)
                table[k][i] = operation.applyAsLong(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }
    }
    private void check(int left, int right) {
        if (left < 0 || left >= right || right > n) throw new IndexOutOfBoundsException();
    }
    // O(1), ONLY for idempotent operations such as min/max/gcd (not sum).
    public long query(int left, int right) { // Nonempty [left, right)
        check(left, right);
        int k = 31 - Integer.numberOfLeadingZeros(right - left);
        return operation.applyAsLong(table[k][left], table[k][right - (1 << k)]);
    }
    // O(log n); disjoint blocks also support sum and other associative operations.
    public long queryAssociative(int left, int right) {
        check(left, right);
        int k = 31 - Integer.numberOfLeadingZeros(right - left);
        long answer = table[k][left];
        left += 1 << k;
        while (left < right) {
            k = 31 - Integer.numberOfLeadingZeros(right - left);
            answer = operation.applyAsLong(answer, table[k][left]);
            left += 1 << k;
        }
        return answer;
    }
    public static void main(String[] args) {
        SparseTable table = new SparseTable(new long[]{4, 2, 7, 1}, Math::min);
        System.out.println(table.query(0, 3)); // 2
    }
}
