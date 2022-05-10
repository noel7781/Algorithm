#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int R, C;
vector<string> board;
vector<pii> ducks;
queue<pii> water_q;
queue<pii> q;
int is_visit[1501][1501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inRange(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    board.resize(R);
    for(int i = 0; i < R; i++) {
        string str; cin >> str;
        board[i] = str;
        for(int j = 0; j < C; j++) {
            if(str[j] == 'L') {
                ducks.push_back({i, j});
                water_q.push({i, j});
            } else if(str[j] == '.') {
                water_q.push({i, j});
            }
        }
    }
    int count = 0;
    is_visit[ducks[0].first][ducks[0].second] = 1;
    q.push(ducks[0]);
    bool is_done = false;
    while(1) {
        queue<pii> next_q;
        while(!q.empty()) {
            auto [cur_y, cur_x] = q.front(); q.pop();
            if(cur_y == ducks[1].first && cur_x == ducks[1].second) {
                is_done = true;
                break; 
            }
            for(int i = 0; i < 4; i++) {
                int nxt_y = cur_y + dy[i], nxt_x = cur_x + dx[i];
                if(inRange(nxt_y, nxt_x) && !is_visit[nxt_y][nxt_x]) {
                    is_visit[nxt_y][nxt_x] = 1;
                    if(board[nxt_y][nxt_x] == 'X') {
                        next_q.push({nxt_y, nxt_x});
                    } else {
                        q.push({nxt_y, nxt_x});
                    }
                }
            }
        }
        if(is_done) break;
        q = next_q;
        next_q = {};
        queue<pii> next_water_q;
        while(!water_q.empty()) {
            auto [cur_y, cur_x] = water_q.front(); water_q.pop();
            for(int i = 0; i < 4; i++) {
                int nxt_y = cur_y + dy[i], nxt_x = cur_x + dx[i];
                if(inRange(nxt_y, nxt_x) && board[nxt_y][nxt_x] == 'X') {
                    next_water_q.push({nxt_y, nxt_x});
                    board[nxt_y][nxt_x] = '.';
                }
            }
        }
        water_q = next_water_q;
        next_water_q = {};
        count++;
    }
    cout << count << "\n";
}