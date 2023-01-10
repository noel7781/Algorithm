#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[51];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2] + 1;
        dp[i] %= MOD;
    }
    cout << dp[N];
}