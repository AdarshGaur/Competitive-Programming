/** Trie for lowercase English letters: O(word length) per operation. */
public class Trie {
    private static class Node {
        final Node[] children = new Node[26];
        boolean word;
    }
    private final Node root = new Node();
    private static void validate(String s) {
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) < 'a' || s.charAt(i) > 'z')
                throw new IllegalArgumentException("Only a-z supported");
    }
    public void insert(String s) {
        validate(s);
        Node node = root;
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if (node.children[c] == null) node.children[c] = new Node();
            node = node.children[c];
        }
        node.word = true;
    }
    private Node walk(String s) {
        validate(s);
        Node node = root;
        for (int i = 0; i < s.length() && node != null; i++) node = node.children[s.charAt(i) - 'a'];
        return node;
    }
    public boolean contains(String s) { Node node = walk(s); return node != null && node.word; }
    public boolean startsWith(String prefix) { return walk(prefix) != null; }
    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("java");
        System.out.println(trie.contains("java")); // true
        System.out.println(trie.contains("jav")); // false
        System.out.println(trie.startsWith("jav")); // true
    }
}
