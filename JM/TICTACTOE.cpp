#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isFinished(vector<string>& board, char turn) {

    if((turn == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    || (turn == board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;
    if((turn == board[0][0] && board[0][0] == board[0][1] && board[0][1] == board[0][2])
    || (turn == board[1][0] && board[1][0] == board[1][1] && board[1][1] == board[1][2])
    || (turn == board[2][0] && board[2][0] == board[2][1] && board[2][1] == board[2][2]))
        return true;
    if((turn == board[0][0] && board[0][0] == board[1][0] && board[1][0] == board[2][0])
    || (turn == board[0][1] && board[0][1] == board[1][1] && board[1][1] == board[2][1])
    || (turn == board[0][2] && board[0][2] == board[1][2] && board[1][2] == board[2][2]))
        return true;
    return false;
}

int bijection(const vector<string>& board) {
    int ret = 0;
    for(int y = 0; y < 3; ++y) {
        for(int x = 0; x < 3; ++x) {
            ret *= 3;
            if(board[y][x] == 'o') ret += 1;
            else if(board[y][x] == 'x') ret += 2;
        }
    }
    return ret;
}

int cache[19683];
int canWin(vector<string>& board, char turn) {
    if(isFinished(board, 'o'+'x'-turn)) {
        return -1;
    }
    int& ret = cache[bijection(board)];
    if(ret != -2) return ret;
    int minValue = 2;
    for(int y = 0; y < 3; ++y) {
        for(int x = 0; x < 3; ++x) {
            if(board[y][x] == '.') {
                board[y][x] = turn;
                minValue = min(minValue, canWin(board, 'o'+'x'-turn));
                board[y][x] = '.';
            }
        }
    }
    if(minValue == 2 || minValue == 0) return ret = 0;
    return ret = -minValue;
}

int main() {
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 19683; ++i) {
            cache[i] = -2;
        }
        vector<string> board(3);
        for(int i = 0; i < 3; ++i) {
            cin >> board[i];
        }
        int char_count = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] != '.')
                    char_count += 1;
            }
        }
        char turn;
        if(char_count % 2 == 0) {
            turn = 'x';
        }
        if(char_count % 2 == 1) {
            turn = 'o';
        }
        int ret = canWin(board, turn);
        if(ret == 1)
            cout << turn << "\n";
        else if(ret == -1)
            cout << 'o' + 'x' - turn << "\n";
        else 
            cout << "TIE\n";
    }
}
