#include <bits/stdc++.h>
using namespace std;
int dp[10001][4];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int k = 4; k <= 10000; k++) {
        for(int m = 1; m <= 3; m++) {
            for(int n = 1; n <= m; n++) {
                dp[k][m] += dp[k-m][n];
            }
        }
    }
    while(t--) {
        int N; cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
    }
    return 0;
}