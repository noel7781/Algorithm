#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int n;

int dx[2] = {0, 1};
int dy[2] = {1, 0};
int cache[101][101];

bool solve(vector<vector<int> >& board, int y, int x) {

    if(y < 0 || x < 0 || y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;

    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    int move = board[y][x];
    return ret = solve(board, y+move, x) || solve(board, y, x+move);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        vector<vector<int> > board;
        board.assign(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        if(solve(board, 0, 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }
}
