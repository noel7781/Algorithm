#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
char board[51][51];
int visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < M;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> board[i][j];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'L') {
                memset(visited, -1, sizeof(visited));
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = 0;
                while(!q.empty()) {
                    pii now = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int ny = now.first + dy[d], nx = now.second + dx[d];
                        if(inRange(ny, nx) && board[ny][nx] == 'L' && visited[ny][nx] == -1) {
                            visited[ny][nx] = visited[now.first][now.second] + 1;
                            ans = max(ans, visited[ny][nx]);
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}