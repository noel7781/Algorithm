#include <bits/stdc++.h>
using namespace std;
int N, L, R;
int board[51][51];
bool is_visit[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int> >& group) {
    for(int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if(0 <= ny && ny < N && 0 <= nx && nx < N) {

            if(!is_visit[ny][nx]) {
                int diff = abs(board[ny][nx] - board[y][x]);
                if(L <= diff && diff <= R) {
                    is_visit[ny][nx] = true;
                    group.push_back({ny, nx});
                    dfs(ny, nx, group);
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int day = 0;
    while(true) {
        memset(is_visit, 0, sizeof(is_visit));
        vector<vector<pair<int, int> > > groups;
        int index = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!is_visit[i][j]) {
                    is_visit[i][j] = 1;
                    vector<pair<int, int> > new_group;
                    new_group.push_back({i, j});
                    dfs(i, j, new_group);
                    if(new_group.size() > 1) groups.push_back(new_group);
                }
            }
        }
        if(groups.size() == 0) break;
        for(const auto& group: groups) {
            int sum = 0;
            int cnt = 0;
            for(const auto& [y, x]: group) {
                sum += board[y][x];
                cnt++;
            }
            int avg = sum / cnt;
            for(const auto& [y, x]: group) {
                board[y][x] = avg;
            }
        }
        day++;
    }
    cout << day << "\n";
}