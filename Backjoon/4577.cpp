#include <bits/stdc++.h>
using namespace std;
char board[16][16];
char original[16][16];
string CMD;
int R = -1, C = -1;
map<char, int> dir = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
bool inRange(int y, int x) {
    return 0 <= y and y < R and 0 <= x and x < C;
}
bool test_plus(int y, int x) {
    return (original[y][x] == '+' || original[y][x] == 'B' || original[y][x] == 'W');
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(1) {
        cin >> R >> C;
        if(R == 0 && C == 0) return 0;
        char x;
        int cur_y = -1, cur_x = -1;
        int left = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> x;
                board[i][j] = x;
                original[i][j] = x;
                if(x == 'w' || x == 'W') {
                    cur_y = i; cur_x = j;
                }
                if(x == 'b') left++;
            }
        }
        cin >> CMD;
        int tt = 1;
        bool is_success = false;
        for(const auto& alpha: CMD) {
            if(left == 0) {
                is_success = true;
                break;
            }
            int d = dir[alpha];
            int nxt_y = cur_y + dy[d], nxt_x = cur_x + dx[d];
            int nnxt_y = nxt_y + dy[d], nnxt_x = nxt_x + dx[d];
            if(!inRange(nxt_y, nxt_x)) continue;
            bool is_done = false;
            switch(board[nxt_y][nxt_x]) {
                case '#':
                    is_done = true;
                    break;
                case '+':
                    board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                    board[nxt_y][nxt_x] = 'W';
                case '.':
                    board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                    board[nxt_y][nxt_x] = 'w';
                    cur_y = nxt_y;
                    cur_x = nxt_x;
                    is_done = true;
                    break;
                case 'b':
                    if(inRange(nnxt_y, nnxt_x)) {
                        char nnxt = board[nnxt_y][nnxt_x];
                        switch(nnxt) {
                            case '#':
                            case 'b':
                            case 'B':
                                break;
                            case '+':
                                board[nnxt_y][nnxt_x] = 'B';
                                board[nxt_y][nxt_x] = 'w';
                                board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                                cur_y = nxt_y;
                                cur_x = nxt_x;
                                left--;
                                break;
                            case '.':
                                board[nnxt_y][nnxt_x] = 'b';
                                board[nxt_y][nxt_x] = 'w';
                                board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                                cur_y = nxt_y;
                                cur_x = nxt_x;
                                break;
                            default:
                                cout << "Error State at b" << "\n";
                                break;
                        }
                    }
                    break;
                case 'B':
                    if(inRange(nnxt_y, nnxt_x)) {
                        char nnxt = board[nnxt_y][nnxt_x];
                        switch(nnxt) {
                            case '#':
                            case 'b':
                            case 'B':
                                break;
                            case '+':
                                board[nnxt_y][nnxt_x] = 'B';
                                board[nxt_y][nxt_x] = 'W';
                                board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                                cur_y = nxt_y;
                                cur_x = nxt_x;
                                break;
                            case '.':
                                board[nnxt_y][nnxt_x] = 'b';
                                board[nxt_y][nxt_x] = 'W';
                                board[cur_y][cur_x] = test_plus(cur_y, cur_x) ? '+' : '.';
                                cur_y = nxt_y;
                                cur_x = nxt_x;
                                left++;
                                break;
                            default:
                                cout << "Error State at B" << "\n";
                                break;
                        }
                    }
                    break;
                default:
                    cout << "Error State\n";
                    break;
            }
        }
        if(left == 0) {
            is_success = true;
        }
        cout << "Game " << t++ <<": " << (is_success ? "complete" : "incomplete") << "\n";
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
}