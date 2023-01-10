#include <bits/stdc++.h>
using namespace std;
int N, M;
int T;
int board[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visited[1001][1001];
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < M;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int j = 0; j < N; j++) {
        for(int k = 0; k < M; k++) {
            int x = 0;
            for(int i = 0; i < 3; i++) {
                int y; cin >> y;
                x += y;
            }
            board[j][k] += x/3;
        }
    }
    cin >> T;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) { 
        if(board[i][j] >= T) {
            board[i][j] = 255;
        } else {
            board[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 255 && !visited[i][j]) {
                ans++;
                visited[i][j] = 1;
                queue<pair<int, int> > q;
                q.push({i, j});
                while(!q.empty()) {
                    const auto [cy, cx] = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int ny = cy + dy[d], nx = cx + dx[d];
                        if(inRange(ny, nx) && board[ny][nx] == 255 && !visited[ny][nx]) {
                            q.push({ny, nx});
                            visited[ny][nx] = 1;
                        }
                    }
                }

            }
        }
    }
    cout << ans;
}