#include <bits/stdc++.h>
using namespace std;
int N, src;
int board[11][11];
int cache[11][1024];
int search(int pos, int visited) {
    if(visited == (1 << N) - 1) {
        return 0;
    }
    int& ret = cache[pos][visited];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = 0; i < N; i++) {
        ret = min(ret, board[pos][i] + search(i, visited | (1 << i))); 
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> src;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> board[i][j];
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    cout << search(src, (1 << src));
}
