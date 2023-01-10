#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int board[301][301];
int tmp[301][301];
bool is_visited[301][301];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < M;
}
int bfs(int y, int x) {
    memset(is_visited, 0, sizeof(is_visited));
    int ret = 1;
    queue<pii> q;
    q.push({y, x});
    is_visited[y][x] = 1;
    while(!q.empty()) {
        auto [cy, cx] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];
            if(inRange(ny, nx) && board[ny][nx] && !is_visited[ny][nx]) {
                is_visited[ny][nx] = 1;
                q.push({ny, nx});
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int left = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j]) left++;
        }
    }
    int ans = 0;
    bool is_done = false;
    while(left > 0) {
        bool is_found = false;
        for(int i = 0; i < N; i++) {
            if(is_found) break;
            for(int j = 0; j < M; j++) {
                if(board[i][j]) {
                    is_found = true;
                    if(bfs(i, j) == left) {
                        left = 0;
                        for(int i = 0; i < N; i++) {
                            for(int j = 0; j < M; j++) {
                                if(board[i][j]) {
                                    int s = 0;
                                    for(int d = 0; d < 4; d++) {
                                        int ny = i + dy[d], nx = j + dx[d];
                                        if(inRange(ny, nx) && board[ny][nx] == 0) {
                                            s++;
                                        }
                                    }
                                    tmp[i][j] = s;
                                }
                            }
                        }
                        for(int i = 0; i < N; i++) {
                            for(int j = 0; j < M; j++) {
                                board[i][j] = max(0, board[i][j] - tmp[i][j]);
                                if(board[i][j]) left++;
                                tmp[i][j] = 0;
                            }
                        }
                    } else {
                        is_done = true;
                    }
                    break;
                }
            }
        }
        if(is_done) break;
        ans++;
    }
    if(left == 0) cout << 0;
    else cout << ans;
}