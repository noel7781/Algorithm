#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int dists[505][505];
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
vector<string> board;
bool inRange1(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}
bool inRange2(int y, int x) {
    return 0 <= y && y <= N && 0 <= x && x <= M;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M;
    board.resize(N);
    for(auto &it: board) cin >> it;
    deque<pii> dq;
    dq.push_back({0, 0});
    dists[0][0] = 0;
    while(!dq.empty()) {
        auto [cur_y, cur_x] = dq.front(); dq.pop_front();
        if(cur_y == N && cur_x == M) {
            cout << dists[N][M] << "\n";
            return 0;
        }
        if(inRange1(cur_y, cur_x) && board[cur_y][cur_x] == '\\') {
            int nxt_y = cur_y + dy[0], nxt_x = cur_x + dx[0];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x];
                dq.push_front({nxt_y, nxt_x});
            }
        } else if(inRange1(cur_y, cur_x) && board[cur_y][cur_x] == '/') {
            int nxt_y = cur_y + dy[0], nxt_x = cur_x + dx[0];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]+1) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x]+1;
                dq.push_back({nxt_y, nxt_x});
            }
        }

        if(inRange1(cur_y-1, cur_x) && board[cur_y-1][cur_x] == '\\') {
            int nxt_y = cur_y + dy[1], nxt_x = cur_x + dx[1];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]+1) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x]+1;
                dq.push_back({nxt_y, nxt_x});
            }
        } else if(inRange1(cur_y-1, cur_x) && board[cur_y-1][cur_x] == '/') {
            int nxt_y = cur_y + dy[1], nxt_x = cur_x + dx[1];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x];
                dq.push_front({nxt_y, nxt_x});
            }
        }

        if(inRange1(cur_y, cur_x-1) && board[cur_y][cur_x-1] == '\\') {
            int nxt_y = cur_y + dy[2], nxt_x = cur_x + dx[2];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]+1) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x]+1;
                dq.push_back({nxt_y, nxt_x});
            }
        } else if(inRange1(cur_y, cur_x-1) && board[cur_y][cur_x-1] == '/') {
            int nxt_y = cur_y + dy[2], nxt_x = cur_x + dx[2];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x];
                dq.push_front({nxt_y, nxt_x});
            }
        }

        if(inRange1(cur_y-1, cur_x-1) && board[cur_y-1][cur_x-1] == '\\') {
            int nxt_y = cur_y + dy[3], nxt_x = cur_x + dx[3];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x];
                dq.push_front({nxt_y, nxt_x});
            }
        } else if(inRange1(cur_y-1, cur_x-1) && board[cur_y-1][cur_x-1] == '/') {
            int nxt_y = cur_y + dy[3], nxt_x = cur_x + dx[3];
            if(inRange2(nxt_y, nxt_x) && dists[nxt_y][nxt_x] > dists[cur_y][cur_x]+1) {
                dists[nxt_y][nxt_x] = dists[cur_y][cur_x]+1;
                dq.push_back({nxt_y, nxt_x});
            }
        }
    }
    cout << "NO SOLUTION\n";
    return 0;
}