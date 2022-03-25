#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N; 
bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
int bfs(vector<vector<int> > board, int H) {
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        if(board[i][j] <= H) board[i][j] = 0;
    }
    int index = 101;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        if(board[i][j] && board[i][j] <= 100) {
            board[i][j] = index;
            queue<pii> q;
            q.push({i, j});
            while(!q.empty()) {
                auto [cy, cx] = q.front(); q.pop();
                for(int j = 0; j < 4; j++) {
                    int ny = cy+dy[j], nx = cx+dx[j];
                    if(inRange(ny, nx)) {
                        if(board[ny][nx] && board[ny][nx] <= 100) {
                            board[ny][nx] = index;
                            q.push({ny, nx});
                        }
                    }
                }
            }
            index++;
        } 
    }
    return index-101;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> board[i][j];
    int ret = 0;
    for(int H = 0; H <= 100; H++) {
        ret = max(ret, bfs(board, H));
    }
    cout << ret << "\n";
}