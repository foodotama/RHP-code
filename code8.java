import java.io.*;
import java.util.*;

public class code8 {
    static int rows, cols;
    static char[][] grid;
    static final int[] DR = {-1, 1, 0, 0};
    static final int[] DC = {0, 0, -1, 1};

    static void dfs(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') return;
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(r + DR[i], c + DC[i]);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        rows = Integer.parseInt(st.nextToken());
        cols = Integer.parseInt(st.nextToken());
        grid = new char[rows][cols];

        for (int i = 0; i < rows; i++) {
            String line = br.readLine().replace(" ", "");
            grid[i] = line.toCharArray();
        }

        int islands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j);
                }
            }
        }

        System.out.println(islands);
    }
}