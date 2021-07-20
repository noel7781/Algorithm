#include <iostream>
#include <vector>

using namespace std;

int N;
int W = 0, B = 0;

int board[130][130];

void solve(int size, int y, int x) {
    if(size == 1 && board[y][x] == 1) {
        B++;
        return;
    } else if(size == 1 && board[y][x] == 0) {
        W++;
        return;
    }
    bool is_same = true;
    int base = board[y][x];
    for(int i = y; i < y+size; ++i) {
        for(int j = x; j < x+size; ++j) {
            if(base != board[i][j]) {
                is_same = false;
                break;
            }
        }
        if(!is_same) {
            break;
        }
    }
    if(is_same && base == 1) {
        B++;
        return;
    } else if(is_same && base == 0) {
        W++;
        return;
    } else {
        solve(size / 2, y, x);
        solve(size / 2, y + size/2, x);
        solve(size / 2, y, x + size/2);
        solve(size / 2, y + size/2, x + size/2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    solve(N, 0, 0);
    cout << W << "\n" << B << "\n";
}