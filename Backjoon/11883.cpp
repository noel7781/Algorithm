#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    dp[3] = 1; dp[5] = 1; dp[8] = 1;
    int sub[] = {3, 5, 8};
    for(int k = 4; k <= 1000000; k++) {
        for(int t = 0; t < 3; t++) {
            int s = sub[t];
            if(k-s >= 0 && dp[k-s]) {
                if(dp[k]) dp[k] = min(dp[k], dp[k-s]+1);
                else dp[k] = dp[k-s]+1;
            }
        }
    }
    while(T--) {
        cin >> N;
        if(dp[N] == 0) {
            cout << -1 << "\n";
        } else {
            while(dp[N] != 1) {
                for(int t = 0; t < 3; t++) {
                    int s = sub[t];
                    if(N-s >= 0) {
                        if(dp[N-s]+1 == dp[N]) {
                            cout << s;
                            N = N-s;
                            break;
                        }
                    }
                }
            }
            cout << N << "\n";
        }

    }
}