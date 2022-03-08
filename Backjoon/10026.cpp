#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> board;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool inRange(int y, int x) {
    return 0 <= x && x < N && 0 <= y && y < N;
}
int solve(int RG) {
    int ans = 0;
    vector<vector<int>> visited(N, vector<int>(N, 0));
    visited[0][0] = 0;
    queue<pair<int, int>> q;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] == 0) {
                ans++;
                visited[i][j] = ans;
                q.push({i, j});
                while(!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        auto ny = y + dy[d], nx = x + dx[d];
                        if(inRange(ny,nx) && visited[ny][nx] == 0) {
                            if(!RG) {
                                if(board[ny][nx] == board[y][x]) {
                                    visited[ny][nx] = ans;
                                    q.push({ny, nx});
                                }
                            } else {
                                if(board[ny][nx] == 'B' && board[y][x] == 'B') {
                                    visited[ny][nx] = ans;
                                    q.push({ny, nx});
                                } else if(board[ny][nx] != 'B' && board[y][x] != 'B') {
                                    visited[ny][nx] = ans;
                                    q.push({ny, nx});
                                }
                            }

                        }

                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    board.resize(N); for(auto &it: board) cin >> it;
    cout << solve(0) << " " << solve(1) << "\n";
}