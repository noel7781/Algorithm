#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
int N, M;
const int BIG_NUMBER = 100;
char board[12][12];
// 오른쪽 아래 왼쪽 위
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int RED, BLUE, HOLE;
int next_red, next_blue;
bool is_visit[1111][1111];

int isOk(int y, int x, int op_y, int op_x) {
    if(y < 0 || y >= N || x < 0 || x >= M) return false;
    if(board[y][x] == '#') return false;
    if(board[y][x] == 'O') return 1;
    if(y == op_y && x == op_x) return false;
    return 2;
}

int move_red(int d) {
    int red_y = next_red / BIG_NUMBER, red_x = next_red % BIG_NUMBER;
    int blue_y = next_blue / BIG_NUMBER, blue_x = next_blue % BIG_NUMBER;
    int cur_y = red_y, cur_x = red_x;
    while(true) {
        int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
        int ret = isOk(nxt_y, nxt_x, blue_y, blue_x);
        if(ret == 1) {
            cur_y = nxt_y; cur_x = nxt_x;
            break;
        } else if(ret == 2) {
            cur_y = nxt_y; cur_x = nxt_x;
        } else {
            break;
        }
    }
    return cur_y * BIG_NUMBER + cur_x;
}
int move_blue(int d) {
    int red_y = next_red / BIG_NUMBER, red_x = next_red % BIG_NUMBER;
    int blue_y = next_blue / BIG_NUMBER, blue_x = next_blue % BIG_NUMBER;
    int cur_y = blue_y, cur_x = blue_x;
    while(true) {
        int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
        int ret = isOk(nxt_y, nxt_x, red_y, red_x);
        if(ret == 1) {
            cur_y = nxt_y; cur_x = nxt_x;
            break;
        } else if(ret == 2) {
            cur_y = nxt_y; cur_x = nxt_x;
        } else {
            break;
        }
    }
    return cur_y * BIG_NUMBER + cur_x;
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
        scanf(" %c", &board[i][j]);
        if(board[i][j] == 'R') {
            RED = i*BIG_NUMBER + j;
        } else if(board[i][j] == 'B') {
            BLUE = i*BIG_NUMBER + j;
        } else if(board[i][j] == 'O') {
            HOLE = i*BIG_NUMBER + j;
        }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, RED, BLUE});
    int ret = 0;
    while(!pq.empty()) {
        auto [cnt, red_pos, blue_pos] = pq.top(); pq.pop();
        if(cnt > 10) {
            ret = -1; break;
        }
        if(is_visit[red_pos][blue_pos]) continue;
        is_visit[red_pos][blue_pos] = 1;
        if(red_pos == HOLE && blue_pos != HOLE) {
            ret = cnt;
            printf("%d\n", ret);
            return 0;
        } else if(blue_pos == HOLE) {
            continue;
        }
        int red_y = red_pos / BIG_NUMBER, red_x = red_pos % BIG_NUMBER;
        int blue_y = blue_pos / BIG_NUMBER, blue_x = blue_pos % BIG_NUMBER;
        // 오른쪽 아래 왼쪽 위
        for(int i = 0; i < 4; i++) {
            next_red = red_pos; next_blue = blue_pos;
            if(i == 0) {
                if(red_x > blue_x) {
                    next_red = move_red(i); next_blue = move_blue(i);
                } else {
                    next_blue = move_blue(i); next_red = move_red(i);
                }
            } else if(i == 1) {
                if(red_y > blue_y) {
                    next_red = move_red(i); next_blue = move_blue(i);
                } else {
                    next_blue = move_blue(i); next_red = move_red(i);
                }
            } else if(i == 2) {
                if(red_x > blue_x) {
                    next_blue = move_blue(i); next_red = move_red(i);
                } else {
                    next_red = move_red(i); next_blue = move_blue(i);
                }
            } else {
                if(red_y > blue_y) {
                    next_blue = move_blue(i); next_red = move_red(i);
                } else {
                    next_red = move_red(i); next_blue = move_blue(i);
                }
            }
            pq.push({cnt+1, next_red, next_blue});
        }
    }
    printf("%d\n", -1);
}