#include <iostream>
#include <vector>

using namespace std;

int connect[501][501];

int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            connect[i][j] = 1e9;
        }
    }
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        connect[a][b] = 1;
    }
    for(int k = 1; k <= n; ++k) {
        for(int a = 1; a <= n; ++a) {
            for(int b = 1; b <= n; ++b) {
                if(connect[a][b] > connect[a][k] + connect[k][b]) {
                    connect[a][b] = connect[a][k] + connect[k][b];
                }
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j =1 ; j <= n; ++j) {
            if(connect[i][j] < 1e9 || connect[j][i] < 1e9) cnt++;
        }
        if(cnt == n-1) ret++;
    }
    cout << ret << "\n";
}