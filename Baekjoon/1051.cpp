#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[51][51];
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) scanf("%1d", &board[i][j]);
    int ret = min(N, M);
    bool is_done = false;
    for(; ret >= 1; ret--) {
        if(is_done) break;
        for(int y = 0; y+ret <= N; y++) {
            if(is_done) break;
            for(int x = 0; x+ret <= M; x++) {
                if(board[y][x] == board[y][x+ret-1] && board[y][x+ret-1] == board[y+ret-1][x+ret-1] && board[y+ret-1][x+ret-1] == board[y+ret-1][x]) {
                    is_done = true;
                    break;
                }
            }
        }
    }
    ret++;
    printf("%d\n", ret*ret);
}