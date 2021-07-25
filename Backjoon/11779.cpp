#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<vector<pii> > g;
int src, dst;

void solve() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, src));
    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1, -1);
    dist[src] = 0;
    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int cur_cost = top.first, cur_pos = top.second;
        if(dist[cur_pos] < cur_cost) continue;
        for(auto next:g[cur_pos]) {
            int next_cost = cur_cost + next.second, next_pos = next.first;
            if(dist[next_pos] > next_cost) {
                dist[next_pos] = next_cost;
                pq.push(pii(next_cost, next_pos));
                parent[next_pos] = cur_pos;
            }
        }
    }
    int min_dist = dist[dst];
    vector<int> path;
    int trace = dst;
    while(trace != -1) {
        path.push_back(trace);
        trace = parent[trace];
    }
    cout << min_dist << "\n";
    cout << path.size() << "\n";
    for(auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g.assign(n+1, vector<pii>());
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(pii(b, c));
    }
    cin >> src >> dst;
    solve();
}
