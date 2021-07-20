#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int col, row, cnt;
int ground[51][51];
bool visit[51][51];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void dfs(int y, int x) {
    for(int i = 0; i < 4; ++i) {
        int dY = y+dy[i], dX = x+dx[i];
        if(dY < 0 || dX < 0 || dY >= row || dX >= col)
            continue;
        if(ground[y+dy[i]][x+dx[i]] && !visit[y+dy[i]][x+dx[i]]) {
            visit[y+dy[i]][x+dx[i]] = true;
            dfs(y+dy[i], x+dx[i]);
        }
    }
    return;
}

int dfsAll() {
    int ret = 0;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(ground[i][j] && !visit[i][j]) {
                dfs(i, j);
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(ground, 0, sizeof(ground));
        memset(visit, 0, sizeof(visit));
        cin >> col >> row >> cnt;
        for(int i = 0; i < cnt; ++i) {
            int y, x; cin >> x >> y;
            ground[y][x] = 1;
        }
        cout << dfsAll() << "\n";
    }
}
