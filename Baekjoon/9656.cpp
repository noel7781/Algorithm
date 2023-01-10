#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for(int k = 4; k <= N; k++) {
        if(dp[k-1] == 0 && dp[k-3] == 0) dp[k] = 1;
        else dp[k] = 0;
    }
    if(dp[N]) {
        cout << "SK\n";
    } else {
        cout << "CY\n";
    }

}