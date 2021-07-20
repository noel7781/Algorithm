#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int V, E, n, m;
vector<vector<pii> > adj;

vector<int> solve(int src) {
    vector<int> dist(V+1, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while(!pq.empty()) {
        int here = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(cost > dist[here]) continue;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextCost = adj[here][i].second + cost;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push(make_pair(there, nextCost));
            }
        }
    }
    return dist;
}

int main() {
    int t; cin >> t;
    while(t--) {
        adj.clear();
        int ret = 0;
        cin >> V >> E >> n >> m;
        vector<int> fired(n);
        vector<int> station(m);
        adj = vector<vector<pii> >(V+1, vector<pii>());
        for(int i = 0; i < E; ++i) {
            int a, b, t; cin >> a >> b >> t;
            adj[a].push_back(make_pair(b, t));
            adj[b].push_back(make_pair(a, t));
        }
        
        for(auto &x: fired) {
            cin >> x;
        }
        for(auto &x: station) {
            cin >> x;
            adj[0].push_back(make_pair(x, 0));
        }
        vector<int> dist = solve(0);
        for(int i = 0; i < n; ++i) {
            ret += dist[fired[i]];
        }
        cout << ret << "\n";
    }
}
