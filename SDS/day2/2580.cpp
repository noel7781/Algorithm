#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<int> > board(9, vector<int>(9, 0));
bool isFound = false;

void solve(vector<vector<int> >& board, int y, int x) {
    if(isFound) return;
    if(y == -1 && x == -1) {
        if(isFound) return;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";                
            }
            cout << endl;
        }
        isFound = true;
        return;
    }
    int next_y = -1, next_x = -1;
    for(int i = y; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(i == y && j > x && board[i][j] == 0) {
                next_y = i; next_x = j;
                break;
            } else if(i > y && board[i][j] == 0) {
                next_y = i; next_x = j;
                break;
            }
        }
        if(next_y != -1) break;
    }
    int dist_y = y / 3, dist_x = x / 3;
    int fill_x = 0b111111111;
    int fill_y = 0b111111111;
    int fill_dist = 0b111111111;
    for(int i = 0; i < 9; ++i) {
        if(board[y][i] != 0) {
            fill_x &= ~(1 << board[y][i]-1);
        }
        if(board[i][x] != 0) {
            fill_y &= ~(1 << board[i][x]-1);
        }
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            int num = board[3*dist_y+i][3*dist_x+j]-1;
            if(num != -1) {
                fill_dist &= ~(1 << num);
            }
        }
    }
    for(int i = 0; i < 9; ++i) {
        if((fill_x & (1 << i)) && (fill_y & (1 << i)) && (fill_dist & (1 <<i))) {
            board[y][x] = i+1;
            solve(board, next_y, next_x);
            board[y][x] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    int src_y = -1, src_x = -1;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == 0) {
                src_y = i; src_x = j;
                break;
            }
        }
        if(src_y != -1) {
            break;
        }
    }
    solve(board, src_y, src_x);
}