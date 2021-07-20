#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;

bool isOk(vector<vector<int> >& board, int y, int x) {
    for(int k = 0; k < y; ++k) {
        if(board[k][x] == 1) return false;
        int diff = y - k ;
        if( (x-diff >= 0 && board[k][x-diff] == 1) || (x+diff < n && board[k][x+diff] == 1))
            return false;
    }
    return true;
}

int solve(vector<vector<int> >& board, int r) {
    if(r == n) return 1;
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        if(isOk(board, r, i)) {
            board[r][i] = 1;
            ret += solve(board, r+1);
            board[r][i] = 0;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);    
    vector<vector<int> > board(n, vector<int>(n, 0));
    int ret = solve(board, 0);
    printf("%d\n", ret);
}