#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int cache[501][501];

int solve(int y, int x, vector<vector<bool> >& visit) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 1;
    visit[y][x] = 1;
    for(int t = 0; t < 4; ++t) {
        int next_y =  y + dy[t], next_x = x + dx[t];
        if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= n) continue;
        if(!visit[next_y][next_x] && m[next_y][next_x] > m[y][x]) {
            ret = max(ret, 1+solve(next_y, next_x, visit));
        }
    }
    visit[y][x] = 0;
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    m.assign(n, vector<int>(n, 0));
    vector<vector<bool> > visit(n, vector<bool>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ret = max(ret, solve(i, j, visit));
        }
    }
    cout << ret << "\n";
    return 0;
}
