#include <bits/stdc++.h>
using namespace std;
int N, M;
int dp[46];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 41; i++) dp[i] = dp[i-1] + dp[i-2];
    int last = 0;
    int acc = 1;
    for(int i = 0; i < M; i++) {
        int x; cin >> x;
        acc *= dp[x - last - 1];
        last = x;
    }
    acc *= dp[N - last];
    cout << acc << "\n";
}