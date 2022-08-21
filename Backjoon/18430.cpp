#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[6][6];
int visited[6][6];
int dy[4][3] = {{0, 0, 1}, {0, -1, 0}, {0, -1, 0}, {0, 0, 1}};
int dx[4][3] = {{0, -1, 0}, {0, 0, -1}, {0, 0, 1}, {0, 1, 0}};
int inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}
int solve(int y, int x) {
    if(y >= N) {
        return 0;
    }
    if(x >= M) {
        return solve(y+1, 0);
    }
    int ret = 0;
    for(int d = 0; d < 4; d++) {
        bool is_ok = true;
        for(int i = 0; i < 3; i++) {
            int ny = y + dy[d][i], nx = x + dx[d][i];
            if(!inRange(ny, nx) || visited[ny][nx]) is_ok = false;
        }
        if(is_ok) {
            int tmp = 0;
            for(int i = 0; i < 3; i++) {
                int ny = y + dy[d][i], nx = x + dx[d][i];
                visited[ny][nx] = 1;
                tmp += (i == 0) ? board[ny][nx] * 2 : board[ny][nx];
            }
            ret = max(ret, tmp + solve(y, x+1));
            for(int i = 0; i < 3; i++) {
                int ny = y + dy[d][i], nx = x + dx[d][i];
                visited[ny][nx] = 0;
            }
        }
    }
    ret = max(ret, solve(y, x+1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0);
    cout << ret << "\n";
}