#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int v, e;
int dp[401][401];

void floyd() {
    for(int k = 1; k <= v; ++k) {
        for(int i = 1; i <= v; ++i) {
            for(int j = 1; j <= v; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}


int main() {
    cin >> v >> e;
    for(int i = 1; i <= v; ++i) {
        for(int j = 1; j <= v; ++j) {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 0; i < e; ++i) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = c;
    }
    floyd();
    int ret = 1e9;
    for(int i = 1; i <= v; ++i) {
        if(dp[i][i] > 0) ret = min(ret, dp[i][i]);
    }
    if(ret >= 1e9) ret = -1;
    cout << ret << "\n";
}
