#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
int R, C;
char board[1001][1001];
int fire_time[1001][1001];
int jh_time[1001][1001];
int dY[4] = {-1, 0, 1, 0};
int dX[4] = {0, 1, 0, -1};
int main() {
    scanf("%d%d", &R, &C);
    queue<pii> fire_q;
    queue<pii> jh;
    memset(fire_time, -1, sizeof(fire_time));
    memset(jh_time, -1, sizeof(jh_time));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'F') {
                fire_time[i][j] = 0;
                fire_q.push(pii(i, j));
            }
            else if(board[i][j] == 'J') {
                jh_time[i][j] = 0;
                jh.push(pii(i, j));
            }
        }
    }
    while(!fire_q.empty()) {
        auto [y, x] = fire_q.front(); fire_q.pop();
        for(int d = 0; d < 4; d++) {
            int next_y = y + dY[d], next_x = x + dX[d];
            if(next_y < 0 || next_x < 0 || next_y >= R || next_x >= C) continue;
            if(board[next_y][next_x] == '#') continue;
            if(fire_time[next_y][next_x] == -1) {
                fire_time[next_y][next_x] = fire_time[y][x] + 1;
                fire_q.push(pii(next_y, next_x));
            }
        }
    }
    while(!jh.empty()) {
        auto [y, x] = jh.front(); jh.pop();
        for(int d = 0; d < 4; d++) {
            int next_y = y + dY[d], next_x = x + dX[d];
            if(next_y < 0 || next_x < 0 || next_y >= R || next_x >= C) {
                printf("%d\n", jh_time[y][x]+1);
                return 0;
            }
            if(board[next_y][next_x] == '#' || jh_time[next_y][next_x] >= 0) continue;
            if(fire_time[next_y][next_x] > jh_time[y][x]+1 || fire_time[next_y][next_x] == -1) {
                jh_time[next_y][next_x] = jh_time[y][x] + 1;
                jh.push(pii(next_y, next_x));
            }
        }
    }
    printf("IMPOSSIBLE\n");
}
