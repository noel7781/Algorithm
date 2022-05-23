#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int H, W;
vector<string> board;
pii src, dst;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dists[501][501];
bool inRange(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}
bool isWall(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(inRange(ny, nx) && board[ny][nx] == '#') return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> H >> W;
    board.resize(H);
    for(auto &it: board) cin >> it;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board[i][j] == 'S') {
                src = {i, j};
            } else if(board[i][j] == 'E') {
                dst = {i, j};
            }
        }
    }

    deque<pii> dq;
    dq.push_back(src);
    dists[src.first][src.second] = 0;
    while(!dq.empty()) {
        auto [cur_y, cur_x] = dq.front(); dq.pop_front();
        if(cur_y == dst.first && cur_x == dst.second) {
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nxt_y = cur_y + dy[i], nxt_x = cur_x + dx[i];
            if(inRange(nxt_y, nxt_x)) {
                if(board[nxt_y][nxt_x] == '.' || board[nxt_y][nxt_x] == 'E') {
                    if(isWall(cur_y, cur_x) && isWall(nxt_y, nxt_x)) {
                        if(dists[nxt_y][nxt_x] > dists[cur_y][cur_x]) {
                            dists[nxt_y][nxt_x] = dists[cur_y][cur_x];
                            dq.push_front({nxt_y, nxt_x});
                        }
                    } else {
                        if(dists[nxt_y][nxt_x] > dists[cur_y][cur_x]+1) {
                            dists[nxt_y][nxt_x] = dists[cur_y][cur_x]+1;
                            dq.push_back({nxt_y, nxt_x});
                        }
                    }
                }
            }
        }

    }
    cout << dists[dst.first][dst.second] << "\n";
}