#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
char map[52][52];
int height[52][52];
int dX[] = {-1,-1,0,1,1,1,0,-1};
int dY[] = {0,1,1,1,0,-1,-1,-1};
pii src;
int dst_cnt = 0;

int bfs(int lo, int hi) {
    queue<pii> q;
    q.push(src);
    vector<vector<bool> > visit(n, vector<bool>(n, 0));
    visit[src.first][src.second] = 1;
    int found = 0;
    if(height[src.first][src.second] > hi || height[src.first][src.second] < lo) return 0;
    while(!q.empty()) {
        pii top = q.front(); q.pop();
        int cur_y = top.first, cur_x = top.second;
        for(int i = 0; i < 8; ++i) {
            int next_y = cur_y + dY[i], next_x = cur_x + dX[i];
            if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= n)
                continue;
            if(!visit[next_y][next_x]) {
                  if(height[next_y][next_x] <= hi && height[next_y][next_x] >= lo) {
                    visit[next_y][next_x] = 1;
                    if(map[next_y][next_x] == 'K') {
                        found += 1;
                    }
                    q.push(pii(next_y, next_x));
                }
            }
        }
    }
    return found;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &n);
    vector<int> hs;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf(" %c", &map[i][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &height[i][j]);
            hs.push_back(height[i][j]);
            if(map[i][j] == 'P') {
                src.first = i; src.second = j;
            } else if(map[i][j] == 'K') {
                dst_cnt += 1;
            }
        }
    }
    sort(hs.begin(), hs.end());
    int ans = hs.back() - hs[0];
    for(int p1 = 0, p2 = 0; p1 < n*n && p2 < n*n && p1 <= p2; ) {
        if(bfs(hs[p1], hs[p2]) == dst_cnt) {
            int tmp = hs[p2] - hs[p1];
            if(tmp < ans) {
                ans = tmp;
            }
            p1++;
        } else {
            p2++;
        }
    }
    printf("%d\n", ans);
}