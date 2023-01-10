#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;
vector<vector<int> > board;
int cache[2048][11];
int virus_count = 0;
vector<pii> virus_pos;
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < N;
}
int solve(int bit_virus_pos) {
    vector<vector<int> > copy_board = board;
    queue<pii> q;
    for(int i = 0; i < virus_count; i++) {
        if(bit_virus_pos & (1 << i)) {
            copy_board[virus_pos[i].first][virus_pos[i].second] = 0;
            q.push({virus_pos[i].first, virus_pos[i].second});
        } else {
            copy_board[virus_pos[i].first][virus_pos[i].second] = -2;
        }
    }
    vector<vector<int> > is_visit(N, vector<int>(N, 0));
    int ret = 0;
    while(!q.empty()) {
        auto [cur_y, cur_x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nxt_y = cur_y + dy[i], nxt_x = cur_x + dx[i];
            if(inRange(nxt_y, nxt_x)) {
                if(copy_board[nxt_y][nxt_x] == -1) {
                    copy_board[nxt_y][nxt_x] = copy_board[cur_y][cur_x] + 1;
                    ret = max(ret, copy_board[nxt_y][nxt_x]);
                    q.push({nxt_y, nxt_x});
                } else if(copy_board[nxt_y][nxt_x] == -2) {
                    copy_board[nxt_y][nxt_x] = copy_board[cur_y][cur_x] + 1;
                    q.push({nxt_y, nxt_x});
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(copy_board[i][j] == -1) return 1e9;
        }
    }
    return ret;
}
int search(int idx, int last) {
    int& ret = cache[idx][last];
    if(ret != -1) return ret;
    if(__builtin_popcount(idx) == M) {
        ret = solve(idx);
        return ret;
    }
    ret = 1e9;
    for(int j = last; j < virus_count; j++) {
        idx |= (1 << j);
        ret = min(ret, search(idx, last+1));
        idx &= ~(1 << j);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    board.resize(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) virus_pos.push_back({i, j});
            else if(board[i][j] == 1) board[i][j] = -11;
            else board[i][j] = -1;

        }
    }
    virus_count = virus_pos.size();
    int idx = 0;
    int ret = search(idx, 0);
    cout << (ret >= 1e9 ? -1 : ret) << "\n";
}