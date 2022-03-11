#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    // 1 0 1 1 1 1
    for(int k = 5; k <= N; k++) {
        if(dp[k-1] && dp[k-3] && dp[k-4]) dp[k] = 0;
        else dp[k] = 1;
    }
    if(dp[N]) {
        cout << "SK\n";
    } else {
        cout << "CY\n";
    }

}