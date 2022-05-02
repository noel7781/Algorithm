import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*; 

public class Main { 
    static int dp[][] = new int[100001][4];
    static final int MOD = 1000000009;

    private static int solve(int n, int before) {
        if(n == 0) {
            return 1;
        }
        int ret = dp[n][before];
        if(ret != -1) return ret;
        ret = 0;
        for(int i = 1; i <= 3; i++) {
            if(before == i) continue;
            if(n >= i) {
                ret += solve(n-i, i);
                ret %= MOD;
            }
        }
        return dp[n][before] = ret;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 100001; i++) {
            Arrays.fill(dp[i], -1);
        }
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            sb.append(solve(N, 0)).append("\n");
        }
        System.out.println(sb);
    } 
}