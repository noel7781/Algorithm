#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int max_dp[2][3];
int min_dp[2][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> board(3, 0);
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            max_dp[i][j] = 0;
            min_dp[i][j] = 0;
        }
    }
    int cur = 0;
    for(int m = 0; m < n; ++m) {
        for(int j = 0; j < 3; ++j ) {
            cin >> board[j];
        }
        for(int i = 0; i < 3; ++i) {
            if(i == 0) {
                max_dp[(cur+1)%2][0] = max(max_dp[cur][0] + board[0], max_dp[cur][1] + board[0]);
                min_dp[(cur+1)%2][0] = min(min_dp[cur][0] + board[0], min_dp[cur][1] + board[0]);
            } else if(i == 2) {
                max_dp[(cur+1)%2][2] = max(max_dp[cur][1] + board[2], max_dp[cur][2] + board[2]);
                min_dp[(cur+1)%2][2] = min(min_dp[cur][1] + board[2], min_dp[cur][2] + board[2]);
            } else {
                max_dp[(cur+1)%2][1] = max(max_dp[cur][0] + board[1], max_dp[cur][1] + board[1]);
                max_dp[(cur+1)%2][1] = max(max_dp[(cur+1)%2][1], max_dp[cur][2] + board[1]);
                min_dp[(cur+1)%2][1] = min(min_dp[cur][0] + board[1], min_dp[cur][1] + board[1]);
                min_dp[(cur+1)%2][1] = min(min_dp[(cur+1)%2][1], min_dp[cur][2] + board[1]);
            }
        }
        cur = (cur+1) % 2;
    }
    int max_ret = 0, min_ret = 1e9;
    for(int j = 0; j < 3; ++j) {
        max_ret = max(max_ret, max_dp[cur][j]);
        min_ret = min(min_ret, min_dp[cur][j]);
    }
    cout << max_ret << " " << min_ret << "\n";

}