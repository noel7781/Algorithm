#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int N, B;
int dp[10001];
int main() {
    cin >> N >> B;
    dp[1] += 1;
    dp[B] += 1;
    for(int i = 2; i <= N; i++) {
        dp[i] += dp[i-1] + dp[max(0,i-B)];
        dp[i] %= MOD;
    }
    cout << dp[N] << "\n";
    return 0;
}