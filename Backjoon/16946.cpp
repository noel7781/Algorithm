#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0}; 
void bfs(int y, int x, int island_idx) {
    queue<pair<int, int>> q;
    q.push({y, x});
    board[y][x] = island_idx;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(board[ny][nx] == 0) {
                board[ny][nx] = island_idx;
                q.push({ny, nx});
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
            board[i][j] *= -1;
        }
    }
    int island_cnt = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0) {
                bfs(i, j, island_cnt++);
            }
        }
    }
    vector<int> area_cnts(island_cnt+1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] > 0) {
                area_cnts[board[i][j]]++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == -1) {
                set<int> s;
                for(int d = 0; d < 4; d++) {
                    int ny = i + dy[d], nx = j + dx[d];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if(board[ny][nx] > 0) {
                        s.insert(board[ny][nx]);
                    }
                }
                int cnt = 0;
                for(auto it = s.begin(); it != s.end(); it++) {
                    cnt += area_cnts[*it];
                }
                cnt++;
                cnt %= 10;
                printf("%d", cnt);
            } else {
                printf("%d", 0);
            }
        }
        printf("\n");
    }

}