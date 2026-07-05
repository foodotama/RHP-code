import java.io.*;
import java.util.*;

public class code13 {
    static int n;
    static double[][][] dp;

    static double solve(int one, int two, int three) {
        if (one == 0 && two == 0 && three == 0) return 0.0;
        if (dp[one][two][three] >= 0) return dp[one][two][three];

        int nonEmpty = one + two + three;
        double ans = (double) n / nonEmpty;
        if (one > 0) ans += (double) one / nonEmpty * solve(one - 1, two, three);
        if (two > 0) ans += (double) two / nonEmpty * solve(one + 1, two - 1, three);
        if (three > 0) ans += (double) three / nonEmpty * solve(one, two + 1, three - 1);
        return dp[one][two][three] = ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        int one = 0, two = 0, three = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int plates = Integer.parseInt(st.nextToken());
            if (plates == 1) one++;
            else if (plates == 2) two++;
            else if (plates == 3) three++;
        }

        dp = new double[n + 1][n + 1][n + 1];
        for (double[][] plane : dp) {
            for (double[] row : plane) {
                Arrays.fill(row, -1.0);
            }
        }

        System.out.printf("%.10f%n", solve(one, two, three));
    }
}