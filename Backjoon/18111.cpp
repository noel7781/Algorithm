#include <bits/stdc++.h>
using namespace std;
int M, N, B;
int board[501][501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> B;
    for(int i=0; i<M; i++) for(int j=0; j<N; j++) cin >> board[i][j];
    int TIME = INT_MAX, H = -1;
    for(int h = 0; h <= 256; h++) {
        int cur_block = B;
        int cur_time = 0;
        bool is_fail = false;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] > h) {
                    cur_time += (board[i][j] - h) * 2;
                    cur_block += (board[i][j] - h);
                }
            }
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] < h) {
                    cur_time += (h - board[i][j]);
                    cur_block -= (h - board[i][j]);
                    if(cur_block < 0) {
                        is_fail = true;
                    }
                }
            }
            if(is_fail) break;
        }
        if(!is_fail) {
            if(TIME >= cur_time) {
                TIME = cur_time;
                H = h;
            }
        }
    }
    cout << TIME << " " << H << "\n";
}