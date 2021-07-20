#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int n, m;
vector<vector<pli> > graph;

vector<ll> solve(vector<vector<pli> >& g) {
    vector<ll> dist(n+1, 1e9);
    dist[1] = 0;
    int cnt = 0;
    bool updated;
    while(cnt < n) {
        updated = false;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] >= 1e8) continue;
            for(auto next: g[i]) {
                ll next_cost = next.first; int next_pos = next.second;
                if(dist[next_pos] > dist[i] + next_cost) {
                    dist[next_pos] = dist[i] + next_cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
        cnt++;
    }
    if(updated) dist.clear(); // 음수루프존재
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.assign(n+1, vector<pli>());
    for(int i = 0; i < m; ++i) {
        int a, b; ll c;
        cin >> a >> b >> c;
        graph[a].push_back(pli(c, b));
    }    
    vector<ll> ret = solve(graph);
    if(ret.empty()) {
        cout << -1 << "\n";
        return 0;
    } else {
        for(int i = 2; i <= n; ++i) {
            ll ans = ret[i];
            if(ans >= 1e8) ans = -1;
            cout << ans << "\n";
        }
    }
}