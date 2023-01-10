#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int> > board(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for(int i = 0; i < m; ++i) {
        cin >> row[i];
    }
    for(int i = n-1; i >= 0; --i) {
        cin >> col[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0) continue;
            board[i][j] = min(row[j], col[i]);
        }
    }
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        int row_max = -1;
        for(int j = 0; j < m; ++j) {
            if(row_max < board[i][j]) {
                row_max = board[i][j];
            }
        }
        if(row_max != col[i]) {
            ok = false;
            break;
        }
    }
    for(int j = 0; j < m; ++j) {
        int col_max = -1;
        for(int i = 0; i < n; ++i) {
            if(col_max < board[i][j]) {
                col_max = board[i][j];
            }
        }
        if(col_max != row[j]) {
            ok = false;
            break;
        }
    }

    if(ok) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}
