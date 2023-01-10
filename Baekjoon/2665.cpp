#include <bits/stdc++.h>
using namespace std;
int N;
string board[51];
typedef tuple<int, int, int> tiii;
int dists[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    memset(dists, 0x3f, sizeof(dists));
    pq.push({0, 0, 0});
    dists[0][0] = 0;
    while(!pq.empty()) {
        auto [blacks, cur_y, cur_x] = pq.top(); pq.pop();
        if(cur_y == N-1 && cur_x == N-1) {
            cout << blacks << "\n";
            return 0;
        }
        if(blacks > dists[cur_y][cur_x]) continue;
        for(int d = 0; d < 4; d++) {
            int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
            if(inRange(nxt_y, nxt_x)) {
                if(dists[nxt_y][nxt_x] > dists[cur_y][cur_x] + '1' - board[cur_y][cur_x]) {
                    dists[nxt_y][nxt_x] = dists[cur_y][cur_x] + '1' - board[cur_y][cur_x];
                    pq.push({blacks + '1' - board[cur_y][cur_x], nxt_y, nxt_x});
                }
            }
        }
    }
    return 0;
}