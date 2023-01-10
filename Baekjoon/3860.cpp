#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> my_t;
int dX[] = {-1, 0, 1, 0};
int dY[] = {0, 1, 0, -1};
int w, h,g, e;

int solve(vector<vector<int> >& graves, my_t portal[][31]) {
    priority_queue<my_t, vector<my_t>, greater<my_t> > pq;
    pq.push(make_pair(0, pii(0, 0)));
    int visit[31][31];
    memset(visit, 0x3f, sizeof(visit));
    while(!pq.empty()) {
        my_t top = pq.top(); pq.pop();
        int time = top.first, cur_y = top.second.first, cur_x = top.second.second;
        if(time < 0) return -10;
        //if(visit[cur_y][cur_x] <= time) return -10;
        visit[cur_y][cur_x] = time;
        if(cur_y == h-1 && cur_x == w-1) return time;
        for(int i = 0; i < 4; ++i) {
            int next_y = cur_y + dY[i], next_x = cur_x + dX[i];
            if(next_y < 0 || next_x < 0 || next_y >= h || next_x >= w) continue;
            if(visit[next_y][next_x] < time) continue;
            if(graves[next_y][next_x] < 0) continue;
            my_t data = portal[next_y][next_x];
            if(data.first != -1e9) {
                int add_time = data.first;
                int nnext_y = data.second.first;;
                int nnext_x = data.second.second;
                if(time+1+add_time < visit[nnext_y][nnext_x])
                    pq.push(make_pair(time+1+add_time, pii(nnext_y, nnext_x)));
            }
            else {
                if(time+1 < visit[next_y][next_x])
                    pq.push(make_pair(time+1, pii(next_y, next_x)));
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.in", "r", stdin);
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;
        cin >> g;
        vector<vector<int> > graves(h, vector<int>(w, 0));
        for(int i = 0; i < g; ++i) {
            int a, b; cin >> a >> b;
            graves[b][a] = -1;
        }
        cin >> e;
        my_t portal[31][31];
        for(int i = 0; i <= 30; ++i) {
            for(int j = 0; j <= 31; ++j) {
                portal[i][j].first = -(int)1e9;
            }
        }

        for(int i = 0; i < e; ++i) {
            int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
            portal[y1][x1] = make_pair(t, pii(y2, x2));
        }
        int ret = solve(graves, portal);
        if(ret == -1) {
            cout << "Impossible\n";
        } else if(ret == -10) {
            cout << "Never\n";
        } else {
            cout << ret << "\n";
        }

    }
}
