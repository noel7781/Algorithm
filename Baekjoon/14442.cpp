#include <bits/stdc++.h>
using namespace std;
int N, M, K;
string board[1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dists[1001][1001][11];
struct Info {
    int cnt;
    int left;
    int y;
    int x;  
};
int inRange(int y, int x ) {
    return 0 <= y && y < N && 0 <= x && x < M;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }
    deque<Info> dq;
    dq.push_back({1, K, 0, 0});
    dists[0][0][K] = 1;
    while(!dq.empty()) {
        auto [cur_cnt, cur_left, cur_y, cur_x] = dq.front(); dq.pop_front();
        if(cur_y == N-1 && cur_x == M-1) {
            cout << cur_cnt << "\n";
            return 0;
        }
        for(int d = 0; d < 4; d++) {
            int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
            if(inRange(nxt_y, nxt_x)) {
                if(cur_left >= 1 && board[nxt_y][nxt_x] == '1') {
                    if(dists[nxt_y][nxt_x][cur_left-1] > dists[cur_y][cur_x][cur_left] + 1) {
                        dists[nxt_y][nxt_x][cur_left-1] = dists[cur_y][cur_x][cur_left] + 1;
                        dq.push_back({cur_cnt+1, cur_left-1, nxt_y, nxt_x});
                    }
                } else if(board[nxt_y][nxt_x] == '0') {
                    if(dists[nxt_y][nxt_x][cur_left] > dists[cur_y][cur_x][cur_left] + 1) {
                        dists[nxt_y][nxt_x][cur_left] = dists[cur_y][cur_x][cur_left] + 1;
                        dq.push_back({cur_cnt+1, cur_left, nxt_y, nxt_x});
                    }
                }
            }
        }

    }
    cout << -1 << "\n";
    return 0;
}
