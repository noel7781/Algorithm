#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int V,E;
vector<vector<pii> > adj;
int N, M;
int X, Y;
vector<int> macs;
vector<int> stars;
vector<int> homes;
vector<int> dijkstra() {
    vector<int> dist(V+1, 1e9);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [cur_cost, cur_pos] = pq.top(); pq.pop();
        if(dist[cur_pos] < cur_cost) continue;
        for(auto next: adj[cur_pos]) {
            int next_pos = next.first;
            int next_cost = cur_cost + next.second;
            if(dist[next_pos] > next_cost) {
                dist[next_pos] = next_cost;
                pq.push({next_cost, next_pos});
            }
        }
    }

    return dist;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    adj.resize(V+1);
    for(int i = 0; i < E; i++) {
        int p1, p2, dist; cin >> p1 >> p2 >> dist;
        adj[p1].push_back({p2, dist});
        adj[p2].push_back({p1, dist});
    }
    homes.resize(V+1, 1);
    homes[0] = 0;
    cin >> N >> X;
    macs.resize(N); for(auto &it: macs) {
        cin >> it;
        homes[it] = 0;
        adj[0].push_back({it, 0});
    }
    vector<int> m_dist = dijkstra();
    for(auto it: macs) {
        adj[0].pop_back();
    }
    cin >> M >> Y;
    stars.resize(M); for(auto &it: stars) {
        cin >> it;
        homes[it] = 0;
        adj[0].push_back({it, 0});
    }
    vector<int> s_dist = dijkstra();
    int ret = 1e9;
    for(int i = 1; i <= V; i++) {
        if(homes[i]) {
            if(m_dist[i] <= X && s_dist[i] <= Y) {
                ret = min(ret, m_dist[i] + s_dist[i]);
            }
        }
    }
    cout << (ret == 1e9 ? -1 : ret) << "\n";
}