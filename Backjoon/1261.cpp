#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0 ,-1};

int solve(vector<vector<char> >& board) {
    priority_queue<pair<int, pii>, vector<pipii>, greater<pipii> > pq;
    int ret = 0;
    bool visit[101][101];
    memset(visit, 0, sizeof(visit));
    pq.push(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()) {
        int cnt = pq.top().first, currY = pq.top().second.first, currX = pq.top().second.second;
        pq.pop();
        if(currY == n-1 && currX == m-1) return cnt;
        for(int i = 0; i < 4; ++i) {
            int nextY = currY + dy[i], nextX = currX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m) continue;
            if(visit[nextY][nextX]) continue;
            if(board[nextY][nextX] == '1') {
                pq.push(make_pair(cnt+1, make_pair(nextY, nextX)));
            } else {
                pq.push(make_pair(cnt, make_pair(nextY, nextX)));
            }
            visit[nextY][nextX] = true;
        }

    }
    return ret;
}

int main() {
    cin >> m >> n;
    vector<vector<char> > board(n, vector<char>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << solve(board) << "\n";
}
