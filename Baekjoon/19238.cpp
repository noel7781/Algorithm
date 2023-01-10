#include <bits/stdc++.h>
using namespace std;
struct YX {
    int y;
    int x;
    int cost;
    bool operator<(const YX& other) const {
        if(cost == other.cost) {
            if(y == other.y) {
                return x > other.x;
            }
            return y > other.y;
        }
        return cost > other.cost;
    }
};
struct Info {
    YX pos;
    int done;
    int exist;
};
int N, M, F;
int src_y, src_x;
int board[21][21];
Info infos[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int y, int x) {
    return 1 <= y and y <= N and 1 <= x and x <= N;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> F;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    cin >> src_y >> src_x;
    for(int i = 0; i < M; i++) {
        int c_y, c_x, d_y, d_x; cin >> c_y >> c_x >> d_y >> d_x;
        infos[c_y][c_x] = {{d_y, d_x, 0}, 0, 1};
    }
    for(int tt = 0; tt < M; tt++) {
        priority_queue<YX> q;
        vector<vector<int> > dists(N+1, vector<int>(N+1, 1e9));
        q.push({src_y, src_x, 0});
        dists[src_y][src_x] = 0;
        int dist = 0;
        bool is_found = false;
        while(!q.empty()) {
            auto [y, x, cost] = q.top(); q.pop();
            if(dists[y][x] < cost) continue;
            auto &info = infos[y][x];
            if(info.exist and !info.done) {
                is_found = true;
                dist = cost;
                src_y = y; src_x = x;
                info.done = 1;
                break;
            }
            for(int d = 0; d < 4; d++) {
                int n_y = y + dy[d], n_x = x + dx[d];
                if(inRange(n_y, n_x) and board[n_y][n_x] == 0 and cost+1 < dists[n_y][n_x]) {
                    dists[n_y][n_x] = cost+1;
                    q.push({n_y, n_x, cost+1});
                }
            }
        }
        F -= dist;
        if(F < 0 || !is_found) {
            cout << -1 << "\n";
            return 0;
        }

        auto &info = infos[src_y][src_x];
        int d_y = info.pos.y, d_x = info.pos.x;
        dists.clear();
        dists.resize(N+1, vector<int>(N+1, 1e9));
        dists[src_y][src_x] = 0;
        q = {};
        dist = 0;
        is_found = false;
        q.push({src_y, src_x, 0});
        while(!q.empty()) {
            auto [y, x, cost] = q.top(); q.pop();
            if(dists[y][x] < cost) continue;
            if(y == d_y and x == d_x) {
                is_found = true;
                dist = cost;
                src_y = y; src_x = x;
                break;
            }
            for(int d = 0; d < 4; d++) {
                int n_y = y + dy[d], n_x = x + dx[d];
                if(inRange(n_y, n_x) and  board[n_y][n_x] == 0 and cost+1 < dists[n_y][n_x]) {
                    dists[n_y][n_x] = cost+1;
                    q.push({n_y, n_x, cost+1});
                }
            }
        }
        if(F < dist || !is_found) {
            cout << -1 << "\n";
            return 0;
        } else {
            F += dist;
        }

    }
    cout << F << "\n";
    return 0;
}