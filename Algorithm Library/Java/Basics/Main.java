import java.io.*;

/** Copy this file as Main.java for a contest submission.
 * Example input: 5 followed by 1 2 3 4 5. Output: 15.
 */
public class Main {
    public static class FastScanner {
        private final InputStream input;
        private final byte[] buffer = new byte[1 << 16];
        private int position, length;
        public FastScanner(InputStream input) { this.input = input; }
        private int read() throws IOException {
            if (position >= length) {
                length = input.read(buffer); position = 0;
                if (length <= 0) return -1;
            }
            return buffer[position++] & 0xff;
        }
        // ASCII whitespace-delimited token, or null at EOF.
        public String next() throws IOException {
            int c;
            do { c = read(); } while (c != -1 && c <= ' ');
            if (c == -1) return null;
            StringBuilder token = new StringBuilder();
            while (c > ' ') { token.append((char) c); c = read(); }
            return token.toString();
        }
        // Parses directly from bytes, including Long.MIN_VALUE, without a token allocation.
        public long nextLong() throws IOException {
            int c;
            do { c = read(); } while (c != -1 && c <= ' ');
            if (c == -1) throw new EOFException("Expected an integer");
            boolean negative = c == '-';
            if (c == '-' || c == '+') c = read();
            long limit = negative ? Long.MIN_VALUE : -Long.MAX_VALUE;
            long value = 0;
            boolean hasDigit = false;
            while (c > ' ') {
                int digit = c - '0';
                if (digit < 0 || digit > 9 || value < limit / 10) throw new NumberFormatException();
                value *= 10;
                if (value < limit + digit) throw new NumberFormatException();
                value -= digit; // Accumulate negatively so Long.MIN_VALUE is representable.
                hasDigit = true; c = read();
            }
            if (!hasDigit) throw new NumberFormatException();
            return negative ? value : -value;
        }
        public int nextInt() throws IOException { return Math.toIntExact(nextLong()); }
    }
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        String first = in.next();
        if (first == null) return;
        int n = Integer.parseInt(first);
        long sum = 0;
        for (int i = 0; i < n; i++) sum += in.nextLong();
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        out.println(sum);
        out.flush();
    }
}
