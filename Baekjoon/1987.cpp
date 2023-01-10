#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int R, C;
vector<vector<char> > board;
bool inRange(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    board.resize(R, vector<char>(C, 0));
    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) cin >> board[i][j];
    queue<tiii> q;
    q.push({0, 0, 1 << (board[0][0] - 'A')});
    int ret = 0;
    while(!q.empty()) {
        auto [cy, cx, visited] = q.front(); q.pop();
        ret = max(ret, __builtin_popcount(visited));
        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];
            if(!inRange(ny, nx)) continue;
            if(visited & (1 << (board[ny][nx]-'A'))) continue;
            q.push({ny, nx, visited | (1 << (board[ny][nx]-'A'))});
        }
    }
    cout << ret << "\n";
}