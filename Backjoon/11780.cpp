#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dp[101][101];
int via[101][101];
int n, m;

void floyd() {
    for(int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
}

void getPath(vector<int>& path, int src, int dst) {
    if(via[src][dst] == 0) {
        path.push_back(src);
        path.push_back(dst);
        return;
    }
    getPath(path, src, via[src][dst]);
    path.pop_back();
    getPath(path, via[src][dst], dst);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    floyd();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(dp[i][j] >= 1e9) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(dp[i][j] == 0 || dp[i][j] >= 1e9) {
                cout << "0\n";
            } else {
                vector<int> tmp;
                getPath(tmp, i, j);
                cout << tmp.size() << " ";
                for(auto it: tmp) { cout << it << " ";}
                cout << "\n";
            }
        }
    }
}
