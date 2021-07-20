#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dX[] = {-1,0,1,0};
int dY[] = {0,1,0,-1};
char board[51][51];
int visit[51][51] = {0, };
bool check[51][51];

int n, m;

int solve(int y, int x, int cnt) {
    if(y < 0 || x < 0 || y >= n || x >= m) return 0;
    if(board[y][x] == 'H') return 0;
    int ret = 0;
    if(check[y][x]) return 1e9;
    else if(visit[y][x] > cnt) return 0;
    visit[y][x] = cnt;
    check[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int move = board[y][x] - '0';
        int next_y = y + dY[i] * move, next_x = x + dX[i] * move;
        ret = max(ret, 1 + solve(next_y, next_x, cnt+1));
        if(ret >= 1e9) {
            cout << -1 << "\n";
            exit(0);
        }
    }
    check[y][x] = 0;
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; ++j) {
            scanf(" %c", &board[i][j]);         
        }
    }
    int ret = solve(0, 0, 0);
    printf("%d\n", ret);
}