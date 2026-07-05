import java.io.*;
import java.util.*;

public class code14 {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int n = fs.nextInt();
        int k = fs.nextInt();
        int q = fs.nextInt();
        int limit = 200000;
        int[] diff = new int[limit + 3];

        for (int i = 0; i < n; i++) {
            int l = fs.nextInt();
            int r = fs.nextInt();
            diff[l]++;
            diff[r + 1]--;
        }

        int[] goodPrefix = new int[limit + 2];
        int active = 0;
        for (int i = 1; i <= limit; i++) {
            active += diff[i];
            goodPrefix[i] = goodPrefix[i - 1] + (active >= k ? 1 : 0);
        }

        StringBuilder out = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            out.append(goodPrefix[b] - goodPrefix[a - 1]).append('\n');
        }
        System.out.print(out);
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int value = 0;
            while (c > ' ') {
                value = value * 10 + c - '0';
                c = read();
            }
            return value * sign;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
    }
}