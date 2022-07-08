#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int x;
int board[101][101];
int dists[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cont = 0;
struct Info {
    int y;
    int x;
    int contNo;
    int dist;
    bool operator<(const Info& r) const {
        return dist > r.dist;
    }
};
bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> x;
            board[i][j] = -x;
        }
    }
    priority_queue<Info> pq;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == -1) {
                queue<pii> q;
                q.push({i, j});
                board[i][j] = ++cont;
                pq.push({i, j, cont, 0});
                while(!q.empty()) {
                    auto [cur_y, cur_x] = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
                        if(!inRange(nxt_y, nxt_x)) continue;
                        if(board[nxt_y][nxt_x] == -1) {
                            board[nxt_y][nxt_x] = cont;
                            q.push({nxt_y, nxt_x});
                            pq.push({nxt_y, nxt_x, cont, 0});
                        }
                    }
                }
            }
        }
    }

    while(!pq.empty()) {
        auto [cur_y, cur_x, cur_cont, cur_dist] = pq.top(); pq.pop();
        int cont = board[cur_y][cur_x];
        if(cont > 0 && cur_cont != cont) {
            cout << cur_dist + dists[cur_y][cur_x] - 1 << "\n";
            return 0;
        }
        for(int d = 0; d < 4; d++) {
            int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
            if(!inRange(nxt_y, nxt_x)) continue;
            if(board[nxt_y][nxt_x] == 0) {
                board[nxt_y][nxt_x] = cur_cont;
                dists[nxt_y][nxt_x] = cur_dist+1;
                pq.push({nxt_y, nxt_x, cur_cont, cur_dist+1});
            } else if(board[nxt_y][nxt_x] != cur_cont) {
                cout << cur_dist + dists[nxt_y][nxt_x] << "\n";
                return 0;
            }
        }
    }
    return 0;
}