/** AVL ordered set of unique long keys. All operations O(log n), space O(n).
 * Java TreeSet has no efficient rank/select; subtree sizes supply those operations.
 */
public class OrderedSet {
    private static class Node {
        long key;
        int height = 1, size = 1;
        Node left, right;
        Node(long key) { this.key = key; }
    }
    private Node root;
    private static int height(Node n) { return n == null ? 0 : n.height; }
    private static int size(Node n) { return n == null ? 0 : n.size; }
    private static void pull(Node n) {
        n.height = 1 + Math.max(height(n.left), height(n.right));
        n.size = 1 + size(n.left) + size(n.right);
    }
    private static Node rotateRight(Node n) {
        Node p = n.left; n.left = p.right; p.right = n;
        pull(n); pull(p); return p;
    }
    private static Node rotateLeft(Node n) {
        Node p = n.right; n.right = p.left; p.left = n;
        pull(n); pull(p); return p;
    }
    private static Node balance(Node n) {
        if (n == null) return null;
        pull(n);
        if (height(n.left) - height(n.right) > 1) {
            if (height(n.left.left) < height(n.left.right)) n.left = rotateLeft(n.left);
            return rotateRight(n);
        }
        if (height(n.right) - height(n.left) > 1) {
            if (height(n.right.right) < height(n.right.left)) n.right = rotateRight(n.right);
            return rotateLeft(n);
        }
        return n;
    }
    private static Node insert(Node n, long key) {
        if (n == null) return new Node(key);
        if (key < n.key) n.left = insert(n.left, key);
        else if (key > n.key) n.right = insert(n.right, key);
        return balance(n);
    }
    private static Node erase(Node n, long key) {
        if (n == null) return null;
        if (key < n.key) n.left = erase(n.left, key);
        else if (key > n.key) n.right = erase(n.right, key);
        else {
            if (n.left == null) return n.right;
            if (n.right == null) return n.left;
            Node successor = n.right;
            while (successor.left != null) successor = successor.left;
            n.key = successor.key;
            n.right = erase(n.right, successor.key);
        }
        return balance(n);
    }
    public int size() { return size(root); }
    public boolean add(long key) { int old = size(); root = insert(root, key); return old != size(); }
    public boolean remove(long key) { int old = size(); root = erase(root, key); return old != size(); }
    public boolean contains(long key) {
        Node n = root;
        while (n != null) {
            if (key == n.key) return true;
            n = key < n.key ? n.left : n.right;
        }
        return false;
    }
    // Number of keys strictly smaller than key (PBDS order_of_key).
    public int orderOfKey(long key) {
        int rank = 0;
        Node n = root;
        while (n != null) {
            if (key <= n.key) n = n.left;
            else { rank += 1 + size(n.left); n = n.right; }
        }
        return rank;
    }
    // k-th SMALLEST key, zero-based (PBDS find_by_order).
    public long findByOrder(int k) {
        if (k < 0 || k >= size()) throw new IndexOutOfBoundsException();
        Node n = root;
        while (true) {
            int leftSize = size(n.left);
            if (k == leftSize) return n.key;
            if (k < leftSize) n = n.left;
            else { k -= leftSize + 1; n = n.right; }
        }
    }
    public static void main(String[] args) {
        OrderedSet set = new OrderedSet();
        for (long key : new long[]{1, 11, 5, 15, 3}) set.add(key);
        System.out.println(set.findByOrder(2)); // 5
        System.out.println(set.orderOfKey(5)); // 2
    }
}
