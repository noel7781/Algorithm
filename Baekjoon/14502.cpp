#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int> > board;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void spread(int y, int x) {
    if(board[y][x] == 0) board[y][x] = 4;
    for(int type = 0; type < 4; ++type) {
        int next_y = y + dy[type], next_x = x + dx[type];
        if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= m) continue;
        if(board[next_y][next_x] == 0) {
            spread(next_y, next_x);
        }
    }
}

int getSafeCount() {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 2) {
                spread(i, j);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0) {
                ret += 1;
            } else if(board[i][j] == 4) {
                board[i][j] = 0;
            }
        }
    }
    return ret;
}

int solve(int y, int x, int count) {
    if(count == 3) {
        int ret = getSafeCount();
        return ret;
    }
    int ret = 0;
    bool find = false;
    for(int i = 0; i < n; ++i) {
        if(y > i) continue;
        for(int j = 0; j < m; ++j) {
            if(y == i && x > j) continue;
            if(board[i][j] == 0) {
                find = true;
                board[i][j] = 1;
                ret = max(ret, solve(i, j, count+1));
                board[i][j] = 0;
            }
        }
    }
    if(!find) return -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j =0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0, 0);
    cout << ret << "\n";
}
