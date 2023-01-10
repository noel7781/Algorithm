#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int dX[] = {-1, 0, 1};
int dY[] = {0, 1, 0};

int n, m;
vector<vector<int > > v;
int cache[1001][1001][3];
bool visit[1001][1001];

int solve(int y, int x, int d) {
    if(y == n-1 && x == m-1) return 0;
    int& ret = cache[y][x][d];
    if(ret != int(-1e9)) return ret;
    ret = -1e8;
    for(int i = 0; i < 3; ++i) {
        int next_y = y + dY[i], next_x = x + dX[i];
        if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= m) continue;
        if(visit[next_y][next_x]) continue;
        visit[next_y][next_x] = 1;
        ret = max(ret, v[next_y][next_x] + solve(next_y, next_x, i));
        visit[next_y][next_x] = 0;
    }
    return ret;
}

int main() {
    for(int i = 0; i <= 1000; ++i) {
        for(int j = 0; j <= 1000; ++j) {
            for(int k = 0; k <= 2; ++k) {
                cache[i][j][k] = int(-1e9);
            }
        }
    }
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    visit[0][0] = 1;
    int ret = v[0][0] + max(solve(0, 0, 1), solve(0, 0, 2));
    cout << ret << "\n";
}

