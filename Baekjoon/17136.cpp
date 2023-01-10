#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int board[10][10];
int use[6];

int solve(int y, int x) {
    for(int i = 1; i <= 5; ++i) {
        if(use[i] > 5) return 10000;
    }
    int cnt = 0;
    int now_y = -1;
    int now_x = -1;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(board[i][j] == 1) {
                now_y = i;
                now_x = j;
                break;
            }
        }
        if(now_y != -1) break;
    }
    if(now_y == -1 && now_x == -1) {
        return 0;
    }
    int ret = 1000;
    bool find = false;
    for(int size = 1; size <= 5; ++size) {
        int one_count = 0;
        for(int i = now_y; i < min(10, now_y+size); ++i) {
            for(int j = now_x; j < min(10, now_x+size); ++j) {
                if(board[i][j] == 1) {
                    one_count += 1;
                }
            }
        }
        if(one_count == size*size) {
            find = true;
            for(int i = now_y; i < now_y+size; ++i) {
                for(int j = now_x; j < now_x+size; ++j) {
                    if(board[i][j] == 1) {
                        board[i][j] = 2;
                    }
                }
            }
            use[size] += 1;
            ret = min(ret, 1+solve(now_y, now_x));
            use[size] -= 1;
            for(int i = now_y; i < now_y+size; ++i) {
                for(int j = now_x; j < now_x+size; ++j) {
                    if(board[i][j] == 2) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
    if(!find) return -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0);
    if(ret == 1000) ret = -1;
    cout << ret << "\n";
}
