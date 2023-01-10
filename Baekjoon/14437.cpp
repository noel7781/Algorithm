#include <iostream>
#include <cstring>

#define MOD 1000000007

using namespace std;

int S;
string str;
int dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> S >> str;
    int len = str.size();
    for(int i = 0; i <= len; i++) {
        dp[i][0] = 1;
    }
    for(int i = 0; i <= 25; i++) {
        dp[1][i] = 1;
    }
    // 사용한 갯수, 위치
    for(int i = 2; i <= len; i++) {
        for(int j = 1; j<= S; j++) {
            for(int k = 0; k <= min(j, 25); k++) {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[len][S] << "\n";
}
