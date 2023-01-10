#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1002];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(V[i] > V[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}