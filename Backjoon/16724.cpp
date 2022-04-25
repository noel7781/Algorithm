#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<string> board;
bool is_visit[1001][1001];
bool is_check[1001][1001];
bool inRange(int y, int x) {
    return 0 <= y and y < N and 0 <= x and x < M;
}
int search(int y, int x) {
    if(!inRange(y, x)) return 0;
    if(!is_check[y][x] && is_visit[y][x]) return 0;
    if(is_check[y][x]) return 1;
    is_visit[y][x] = 1;
    is_check[y][x] = 1;
    int ret = 0;
    switch(board[y][x]) {
        case 'U':
            ret = search(y-1, x);
            break;
        case 'D':
            ret = search(y+1, x);
            break;
        case 'R':
            ret = search(y, x+1);
            break;
        case 'L':
            ret = search(y, x-1);
            break;
        default:
            break;
    }
    is_check[y][x] = 0;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    board.resize(N); for(auto &it: board) cin >> it;
    int ret = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!is_visit[i][j]) {
                ret += search(i, j);
            }
        }
    }
    cout << ret << "\n";
}