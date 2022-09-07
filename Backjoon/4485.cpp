#include <bits/stdc++.h>
using namespace std;
int board[126][126];
int dists[126][126];
int N = -1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
struct Info {
    int y;
    int x;
    int cost;
    bool operator<(const Info& rhs) const {
        return cost > rhs.cost;
    }
};
bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(cin >> N) {
        if(N == 0) return 0;
        memset(dists, 0x3f, sizeof(dists));
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> board[i][j];
        priority_queue<Info> pq;
        dists[0][0] = board[0][0];
        pq.push({0, 0, dists[0][0]});
        while(!pq.empty()) {
            const auto [cy, cx, cc] = pq.top(); pq.pop();
            for(int d = 0; d < 4; d++) {
                int ny = cy + dy[d], nx = cx + dx[d];
                if(inRange(ny, nx)) {
                    int nc = cc + board[ny][nx];
                    if(dists[ny][nx] > nc) {
                        dists[ny][nx] = nc;
                        pq.push({ny, nx, nc});
                    }
                }
            }
        }
        cout << "Problem " << t << ": " << dists[N-1][N-1] << "\n";
        t++;
    }
}