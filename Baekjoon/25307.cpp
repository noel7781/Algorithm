#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, K;
int board[2001][2001];
int dists[2001][2001];
pii src, dst;
vector<pii> manes;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int get_distance(pii& A, pii& B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < M;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    memset(dists, 0x3f, sizeof(dists));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 4) src = {i, j};
            else if(board[i][j] == 3) manes.push_back({i, j});
        }
    }
    queue<pair<pii, int> > q;
    for(auto mane: manes) {
        q.push({mane, 0});
        dists[mane.first][mane.second] = -1;
        while(!q.empty()) {
            auto [pos, cost] = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if(cost+1 > K) break;
                if(inRange(ny, nx)) {
                    if(dists[ny][nx] == -1) continue;
                    q.push({{ny, nx}, cost+1});
                    dists[ny][nx] = -1;
                }
            }
        }
    }
    queue<pii> qq;
    qq.push(src);
    dists[src.first][src.second] = 0;
    while(!qq.empty()) {
        auto pos = qq.front(); qq.pop();
        if(board[pos.first][pos.second] == 2) {
            cout << dists[pos.first][pos.second] << "\n";
            return 0;
        }
        for(int d = 0; d < 4; d++) {
            int ny = pos.first + dy[d], nx = pos.second + dx[d];
            if(inRange(ny, nx) && (board[ny][nx] == 0 || board[ny][nx] == 2) && dists[ny][nx] != -1) {
                if(dists[ny][nx] > dists[pos.first][pos.second] + 1) {
                    qq.push({ny, nx});
                    dists[ny][nx] = dists[pos.first][pos.second]+1;
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}