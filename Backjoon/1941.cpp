#include <bits/stdc++.h>
using namespace std;
string board[5];
int dx[] = {1, 0, 0};
int dy[] = {0, 1, -1};
struct Info {
    int y; int x;
    int acc;
    int Slen;
};
bool inRange(int y, int x) {
    return 0 <= y && y < 5 && 0 <= x && x < 5;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 5; i++) {
        cin >> board[i];
    }
    set<int> s;
    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 5; j++) {
            // printf("i = %d j = %d\n", i, j);
            int i = 1, j = 0;
            queue<Info> q;
            int pos = 5*i + j;
            if(board[i][j] == 'S') {
                q.push({i, j, (1<<pos), 1});
            } else {
                q.push({i, j, (1<<pos), 0});
            }
            while(!q.empty()) {
                auto [curr_y, curr_x, curr_acc, curr_Slen] = q.front(); q.pop();
                printf("[%d, %d], acc = %d, S = %d\n", curr_y, curr_x, __builtin_popcount(curr_acc), curr_Slen);
                if(__builtin_popcount(curr_acc) == 7) {
                    if(curr_Slen >= 4) {
                        printf("acc = %d\n", curr_acc);
                        s.insert(curr_acc);
                    }
                    continue;
                }
                for(int d = 0; d < 4; d++) {
                    int nxt_y = curr_y + dy[d], nxt_x = curr_x + dx[d];
                    if(!inRange(nxt_y, nxt_x)) continue;
                    int nxt_pos = nxt_y * 5 + nxt_x;
                    if(curr_acc & (1 << nxt_pos)) continue;
                    if(board[nxt_y][nxt_x] == 'S') {
                        q.push({nxt_y, nxt_x, curr_acc | (1 << nxt_pos), curr_Slen+1});
                    } else {
                        q.push({nxt_y, nxt_x, curr_acc | (1 << nxt_pos), curr_Slen});
                    }
                }
            }
    //     }
    // }
    cout << s.size() << "\n";
}