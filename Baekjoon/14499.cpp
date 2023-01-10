#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, x, y, k;
vector<vector<int> > board;
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void change(vector<int>& dice, int d) {
    if(d == 1) {
        swap(dice[0], dice[5]);
        swap(dice[1], dice[4]);
        swap(dice[4], dice[5]);
    } else if(d == 2) {
        swap(dice[1], dice[5]);
        swap(dice[0], dice[4]);
        swap(dice[4], dice[5]);
        
    } else if(d == 3) {
        swap(dice[0], dice[2]);
        swap(dice[1], dice[3]);
        swap(dice[2], dice[3]);

    } else {
        swap(dice[0], dice[3]);
        swap(dice[1], dice[2]);
        swap(dice[2], dice[3]);
    }
    return;
}

int solve(vector<int>& dice, int y, int x, int d) {
    int next_y = y+dy[d], next_x = x+dx[d];
    if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= m) return -1;
    change(dice, d);
    if(board[next_y][next_x] == 0) {
        board[next_y][next_x] = dice[1];
    } else {
        dice[1] = board[next_y][next_x];
        board[next_y][next_x] = 0;
    }
    return dice[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> y >> x >> k;
    board.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    vector<int> dice(6, 0);
    int d = -1;
    for(int i = 0; i < k; ++i) {
        cin >> d;
        int ret = solve(dice, y, x, d);
        if(ret != -1) {
            cout << ret << "\n";
            y += dy[d];
            x += dx[d];
        }
    }
}
