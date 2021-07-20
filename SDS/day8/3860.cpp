#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int dX[] = {-1, 0 ,1 ,0};
int dY[] = {0, -1, 0, 1};

int w, h, g, e;
int BIG_NUMBER = 1e6;
vector<vector<int> > board;
vector<vector<pii> > graph;
void solve() {
    // 노드 추가 과정
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            // 마지막 노드에서는 추가x
            if(i == h-1 && j == w-1) continue;
            // 묘비면 노드추가 x
            if(board[i][j]) continue;
            // 귀신구멍이면 노드추가 x, main에서 함.
            if(!graph[i*w+j].empty()) continue;
            for(int k = 0; k < 4; ++k) {
                int next_y = i + dY[k], next_x = j + dX[k];
                // 맵 바깥인 경우 노드추가 x
                if(next_y < 0 || next_x < 0 || next_y >= h || next_x >= w) continue;
                graph[i*w+j].push_back(pii(next_y*w+next_x, 1));
            }
        }
    }
    vector<int> dist(h*w, 1e9);
    dist[0] = 0;
    bool update;
    for(int k = 0; k < h*w; ++k) {
        update = false;
        for(int i = 0; i < h*w; ++i) {
            if(dist[i] >= 1e9) continue;
            int ypos = i / w, xpos = i % w;
            for(int j = 0; j < graph[i].size(); ++j) {
                pii next = graph[i][j];
                int cost = next.second; int pos = next.first;
                if(dist[pos] > dist[i] + cost) {
                    update = true;
                    dist[pos] = dist[i] + cost;
                }
            }
        }
        if(!update) break;
    }
    if(update) {
        cout << "Never\n";
        return;
    } else if(dist[h*w-1] >= 1e8) {
        cout << "Impossible\n";
    } else {
        cout << dist[h*w-1] << "\n";
    }
    return;
}

int main() {
    while(cin >> w >> h) {
        if(w == 0 && h == 0) return 0;
        graph.clear();
        board.clear();
        board.assign(h, vector<int>(w, 0));
        graph.assign(w*h, vector<pii>());
        cin >> g;
        for(int i = 0; i < g; ++i) {
            int a, b; cin >> a >> b;
            board[b][a] = 1;
        }
        cin >> e;
        for(int i = 0; i < e; ++i) {
            int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
            // warp[y1][x1] = y2 * BIG_NUMBER + x2; warp_time[y1][x1] = BIG_NUMBER + t;
            graph[y1*w+x1].push_back(pii(y2*w+x2, t));
        }
        solve();
    }
}