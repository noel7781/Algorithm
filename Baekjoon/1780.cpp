#include <iostream>
#include <vector>

using namespace std;

int N;
int A = 0, B = 0, C = 0;

int board[2200][2200];

void solve(int size, int y, int x) {
    if(size == 1 && board[y][x] == -1) {
        A++;
        return;
    } else if(size == 1 && board[y][x] == 0) {
        B++;
        return;
    } else if(size == 1 && board[y][x] == 1) {
        C++;
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
    if(is_same && base == -1) {
        A++;
        return;
    } else if(is_same && base == 0) {
        B++;
        return;
    }  else if(is_same && base == 1) {
        C++;
        return;
    } else {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                solve(size / 3, y + (size/3) * i, x + (size/3) * j);
            }
        }
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
    cout << A << "\n" << B << "\n" << C << "\n";
}