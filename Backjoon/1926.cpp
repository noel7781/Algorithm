#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int board[501][501];
bool is_visit[501][501];
int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int p_cnt = 0;
    int max_s = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!is_visit[i][j] && board[i][j] == 1) {
                int s = 0;
                p_cnt += 1;
                queue<pii> q;
                q.push(pii(i, j));
                is_visit[i][j] = true;
                while(!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    s += 1;
                    for(int k = 0; k < 4; k++) {
                        int n_y = y + dY[k], n_x = x + dX[k];
                        if(n_y < 0 || n_x < 0 || n_y >= n || n_x >= m) continue;
                        if(is_visit[n_y][n_x] || board[n_y][n_x] == 0) continue;
                        is_visit[n_y][n_x] = true;
                        q.push(pii(n_y, n_x));
                    }
                }
                max_s = max(max_s, s);
            }
        }
    }
    cout << p_cnt << "\n" << max_s << "\n";
}
