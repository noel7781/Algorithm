#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A, B, C; cin >> A >> B >> C;
    int a = A.size(), b = B.size(), c = C.size();
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    cout << dp[a][b][c] << "\n";
}