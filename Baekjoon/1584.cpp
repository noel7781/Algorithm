#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int X1, Y1, X2, Y2;
int state[501][501];
int dists[501][501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int y, int x) {
    return 0 <= y && y <= 500 && 0 <= x && x <= 500;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        for(int i = min(Y1, Y2); i <= max(Y1, Y2); i++) {
            for(int j = min(X1, X2); j <= max(X1, X2); j++) {
                state[i][j] = 1;
            }
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        for(int i = min(Y1, Y2); i <= max(Y1, Y2); i++) {
            for(int j = min(X1, X2); j <= max(X1, X2); j++) {
                state[i][j] = 2;
            }
        }
    }
    deque<pii> dq;
    dq.push_back({0, 0});
    dists[0][0] = 0;
    while(!dq.empty()) {
        auto [y, x] = dq.front(); dq.pop_front();
        if(y == 500 && x == 500) {
            cout << dists[y][x] << "\n";
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(!inRange(ny, nx)) continue;
            int st = state[ny][nx];
            if(st == 0 && dists[ny][nx] > dists[y][x]) {
                dq.push_front({ny, nx});
                dists[ny][nx] = dists[y][x];
            } else if(st == 1 && dists[ny][nx] > dists[y][x] + 1) {
                dq.push_back({ny, nx});
                dists[ny][nx] = dists[y][x] + 1;
            }
        }
    }
    cout << -1 << "\n";
}