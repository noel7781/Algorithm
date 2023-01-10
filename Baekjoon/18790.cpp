#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
bool dp[1001][501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    V.resize(2*N-1);
    for(auto &it: V) cin >> it;
    dp[0][0][0] = 1;
    dp[0][1][V[0]] = 1;
    for(int i = 1; i < 2*N-1; i++) {
        for(int j = 0; j <= min(i+1, N); j++) {
            for(int k = 0; k < N; k++) {
                dp[i][j][k] |= dp[i-1][j][k];
                if(j >= 1) dp[i][j][k] |= dp[i-1][j-1][(k-V[i]+N)%N];
            }
        }
    }
    if(dp[2*N-2][N][0]) {
        vector<int> path;
        int i = 2*N-2, j = N, k = 0;
        while(i >= 1) {
            bool now = dp[i][j][k];
            bool d1 = dp[i-1][j][k], d2 = dp[i-1][j-1][(k-V[i]+N)%N];
            if(now == d2) {
                path.push_back(V[i]);
                k = (k-V[i]+N)%N;
                i--;
                j--;
            } else {
                i--;
            }
        }
        if(path.size() < N && dp[i][j][k]) {
            path.push_back(V[i]);
        } 
        for(auto &it: path) cout << it << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}