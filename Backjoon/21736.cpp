#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
char board[601][601];

int main() {
    int is_visit[601][601];
    queue<pii> q;
    scanf("%d %d", &N, &M);
    pii doyeon_pos;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'I') {
                doyeon_pos = pii(i, j);
                is_visit[i][j] = 1;
            }
        }
    }
    q.push(doyeon_pos);
    int ret = 0;
    while(!q.empty()) {
        pii nowPos = q.front(); q.pop();
        int nowY = nowPos.first, nowX = nowPos.second;
        if(board[nowY][nowX] == 'P') ret++;
        for(int i = 0; i < 4; i++) {
            int nextY = nowY + dy[i], nextX = nowX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
            if(is_visit[nextY][nextX] || board[nextY][nextX] == 'X') continue;
            q.push(pii(nextY, nextX));
            is_visit[nextY][nextX] = 1;
        }

    }
    if(ret != 0) 
        printf("%d\n", ret);
    else
        printf("TT\n");
    return 0;
}
