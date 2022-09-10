
#include<iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int R, C;
int ans = 0;

int moveA(vector<vector<int>>& board, pii A, pii B);
int moveB(vector<vector<int>>& board, pii A, pii B);

bool inRange(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}

bool canMove(vector<vector<int>>& board, pii& pos) {
    int y = pos.first, x = pos.second;
    if(board[y][x] == 0) return false;
    for(int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if(inRange(ny, nx) && board[ny][nx] == 1) return true;
    }
    return false;
}

int search(vector<vector<int>>& board, int turn, pii apos, pii bpos) {
    int ret = 0;
    if((turn == 0 && board[apos.first][apos.second] == 0) || (turn == 1 && board[bpos.first][bpos.second] == 0)) return 0;
    if(turn == 0) {
        int y = apos.first, x = apos.second;
        if(moveA(board, apos, bpos) == 1) {
            ret = 1e9;
            for(int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if(inRange(ny, nx) && board[ny][nx] == 1) {
                    board[y][x] = 0;
                    if(moveB(board, {ny, nx}, bpos) == 1) {
                        board[y][x] = 1;
                        continue;
                    }
                    ret = min(ret, 1 + search(board, 1, {ny, nx}, bpos));
                    board[y][x] = 1;
                }
            }
        } else {
            ret = 0;
            for(int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if(inRange(ny, nx) && board[ny][nx] == 1) {
                    board[y][x] = 0;
                    ret = max(ret, 1 + search(board, 1, {ny, nx}, bpos));
                    board[y][x] = 1;
                }
            }
        }
    } else {
        int y = bpos.first, x = bpos.second;
        if(moveB(board, apos, bpos) == 1) {
            ret = 1e9;
            for(int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if(inRange(ny, nx) && board[ny][nx] == 1) {
                    board[y][x] = 0;
                    if(moveA(board, apos, {ny, nx}) == 1) {
                        board[y][x] = 1;
                        continue;
                    }
                    ret = min(ret, 1 + search(board, 0, apos, {ny, nx}));
                    board[y][x] = 1;
                }
            }
        } else {
            ret = 0;
            for(int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if(inRange(ny, nx) && board[ny][nx] == 1) {
                    board[y][x] = 0;
                    ret = max(ret, 1 + search(board, 0, apos, {ny, nx}));
                    board[y][x] = 1;
                }
            }
        }
    }
    return ret;
}

int moveA(vector<vector<int>>& board, pii apos, pii bpos) {
    if(!canMove(board, apos)) {
        return 0;
    }
    int b_move = 1;
    int y = apos.first, x = apos.second;
    for(int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if(inRange(ny, nx) && board[ny][nx] == 1) {
            board[y][x] = 0;
            b_move &= moveB(board, {ny, nx}, bpos);
            board[y][x] = 1;
        }
    }
    return b_move ^ 1;
}
int moveB(vector<vector<int>>& board, pii apos, pii bpos) {
    if(!canMove(board, bpos)) {
        return 0;
    }
    int a_move = 1;
    int y = bpos.first, x = bpos.second;
    for(int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if(inRange(ny, nx) && board[ny][nx] == 1) {
            board[y][x] = 0;
            a_move &= moveA(board, apos, {ny, nx});
            board[y][x] = 1;
        }
    }
    return a_move ^ 1;
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	R = board.size(); C = board[0].size();
    int answer = -1;
    pii A = {aloc[0], aloc[1]}; pii B = {bloc[0], bloc[1]};
    answer = search(board, 0, A, B);
    return answer;
}