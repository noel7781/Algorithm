#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int board[1001][1001];
int dX[] = {1, 0, 1};
int dY[] = {0, 1, 1};
int cache[1001][1001];
int solve(int y, int x) {
    if(y == n-1 && x == m-1) return board[y][x];
    if(y >= n || x >= m) return -1e9;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 3; i++) {
        int n_y = y + dY[i], n_x = x + dX[i];
        ret = max(ret, board[y][x] + solve(n_y, n_x));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0);
    cout << ret << "\n";
}
