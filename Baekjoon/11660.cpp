#include <iostream>
#include <vector>

using namespace std;

int size, cnt;
int sum_board[1024][1024];

int calc_sum(vector<vector<int> >& board, int y, int x) {
    if(sum_board[y][x] > 0)
        return sum_board[y][x];
    if(x==0 && y ==0) {
        sum_board[y][x] = board[y][x];
        return sum_board[y][x];
    }
    if(x==0) {
        sum_board[y][x] = board[y][x] + calc_sum(board, y-1, x);
        return sum_board[y][x];
    }
    if(y==0) {
        sum_board[y][x] = board[y][x] + calc_sum(board, y, x-1);
        return sum_board[y][x];
    }
    sum_board[y][x] = calc_sum(board, y - 1, x) + calc_sum(board, y, x - 1) + board[y][x] - calc_sum(board, y-1, x-1);
    return sum_board[y][x];
}

int solve(int x1, int y1, int x2, int y2) {
    if(x1 == 0 && y1 == 0) 
        return sum_board[y2][x2];
    if(x1 == 0) {
        return sum_board[y2][x2] - sum_board[y1-1][x2]; 
    }
    if(y1 == 0) {
        return sum_board[y2][x2] - sum_board[y2][x1-1];
    }
    return sum_board[y2][x2] - sum_board[y2][x1-1] - sum_board[y1-1][x2] + sum_board[y1-1][x1-1];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> size >> cnt;
    vector<vector<int> > board(size);
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            int num; cin >> num;
            board[i].push_back(num);
        }
    }
    sum_board[0][0] = board[0][0];
    calc_sum(board, size - 1, size - 1);
    while(cnt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(y1-1, x1-1, y2-1, x2-1) << "\n";
    }
}
