#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int v, e;
int src;

void solve(vector<vector<pii> >& g, int s) {
    vector<int> dist(v+1, 1e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, s));
    dist[s] = 0;
    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int cur_cost = top.first, cur_pos = top.second;
        // if(dist[cur_pos] < cur_cost) continue;
        for(auto next: g[cur_pos]) {
            int next_cost = next.second + cur_cost, next_pos = next.first;
            if(dist[next_pos] > next_cost) {
                dist[next_pos] = next_cost;
                pq.push(pii(next_cost, next_pos));
            }
        }
    }
    for(int i = 1; i <= v; ++i) {
        int p = dist[i];
        if(p >= 1e9) {
            cout << "INF\n";
        } else {
            cout << p << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> src;
    vector<vector<pii> > g(v+1);
    for(int i = 0; i < e; ++i) {
        int f, t, c; cin >> f >> t >> c;
        g[f].push_back(pii(t, c));
    }
    solve(g, src);
}