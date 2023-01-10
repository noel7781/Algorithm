#include <bits/stdc++.h>
using namespace std;
int N;
int board[11][11];
int cache[11][1024];
int solve(int pos, int visited) {
    if(visited == (1 << N) - 1) {
        return board[pos][0] != 0 ? board[pos][0] : 1e9;
    }
    int& ret = cache[pos][visited];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int j = 0; j < N; j++) {
        if(visited & (1 << j) || board[pos][j] == 0) continue;
        ret = min(ret, board[pos][j] + solve(j, visited | (1 << j)));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int visited = 1;
    int ret = solve(0, visited);
    cout << ret << "\n";
    return 0;
}