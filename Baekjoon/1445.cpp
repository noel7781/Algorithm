#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct Info {
    int y; int x; int dir; int indir;
    bool operator<(const Info& rhs) const {
        if(dir == rhs.dir) {
            return indir > rhs.indir;
        }
        return dir > rhs.dir;
    }
};
char board[51][51];
int N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
pii dists[51][51];
pii src, dst;
int inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}
bool check_around(int y, int x) {
    for(int d = 0; d < 4; d++) {
        int nxt_y = y + dy[d], nxt_x = x + dx[d];
        if(inRange(nxt_y, nxt_x) && board[nxt_y][nxt_x] == 'g') return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'F') dst = {i, j};
            if(board[i][j] == 'S') src = {i, j};
        }
    }
    priority_queue<Info> pq;
    pq.push({src.first, src.second, 0, 0});
    dists[src.first][src.second] = {0, 0};
    while(!pq.empty()) {
        auto [cur_y, cur_x, cur_dir, cur_indir] = pq.top(); pq.pop();
        if(dists[cur_y][cur_x].first > cur_dir || (dists[cur_y][cur_x].first == cur_dir && dists[cur_y][cur_x].second > cur_indir)) continue;
        if(board[cur_y][cur_x] == 'F') {
            cout << cur_dir << " " <<cur_indir << "\n";
            return 0;
        }
        for(int d = 0; d < 4; d++) {
            int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
            if(inRange(nxt_y, nxt_x)) {
                int next = (board[nxt_y][nxt_x] == 'g');
                int around = (board[nxt_y][nxt_x] == '.' ? check_around(nxt_y, nxt_x) : 0);
                if(dists[nxt_y][nxt_x].first > cur_dir + next || (dists[nxt_y][nxt_x].first == cur_dir + next && dists[nxt_y][nxt_x].second > cur_indir+around)) {
                    dists[nxt_y][nxt_x] = {cur_dir+next, cur_indir + around};
                    pq.push({nxt_y, nxt_x, cur_dir + next, cur_indir + around});
                }
            }
        }

    }

}