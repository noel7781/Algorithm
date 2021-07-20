#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;


int n, m;
int s, d;

vector<int> dijk(vector<vector<pii> >& g, int src) {
    vector<int> ret(n, 1e9);
    ret[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, src));
    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int cur_cost = top.first, cur_pos = top.second;
        for(auto next: g[cur_pos]) {
            int next_cost = cur_cost + next.first, next_pos = next.second;
            if(ret[next_pos] > next_cost) {
                ret[next_pos] = next_cost;
                pq.push(pii(next_cost, next_pos));
            }
        }
    }
    return ret;
}

void solve(vector<vector<pii> >& g, vector<vector<pii> >& r_g, vector<int>& dist, int d) {
    queue<int> q;
    q.push(d);
    while(!q.empty()) {
        int pos = q.front(); q.pop();
        for(auto it = r_g[pos].begin(); it != r_g[pos].end();) {
            int next = (*it).second;
            int diff = (*it).first;
            if(dist[pos] - dist[next] == diff) {
                q.push(next);
                it = r_g[pos].erase(it);
            } else {
                it++;
            }
        }
    }
    g.clear();
    g.assign(n, vector<pii>());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < r_g[i].size(); ++j) {
            int next = r_g[i][j].second, cost = r_g[i][j].first;
            g[next].push_back(pii(cost, i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        cin >> s >> d;
        vector<vector<pii> > g(n, vector<pii>());
        vector<vector<pii> > r_g(n, vector<pii>());
        for(int i = 0; i < m; ++i) {
            int a, b, c; cin >> a >> b >> c;
            g[a].push_back(pii(c, b));
            r_g[b].push_back(pii(c, a));
        }
        vector<int> dist = dijk(g, s);
        solve(g, r_g, dist, d);
        dist = dijk(g, s);
        if(dist[d] >= 1e9) dist[d] = -1;
        cout << dist[d] << "\n";
    }
}