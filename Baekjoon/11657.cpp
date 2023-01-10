#include <iostream>
#include <vector>

#define INF 987654321
#define SEMI 90000000

using namespace std;

typedef long long ll;

int n, m;
vector<vector<pair<int, ll> > > adj;

void solve(int src) {
    vector<ll> dist(n+1, INF);
    dist[src] = 0;
    bool updated;
    for(int iter = 0; iter < n; ++iter) {
        updated = false;
        for(int here = 1; here <= n; ++here) {
            for(int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                ll cost = adj[here][i].second;
                if(dist[there] > dist[here] + cost) {
                    dist[there] = dist[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) {
        cout << -1  << "\n";
        return;
    }        
    for(int i = 2; i <= n; ++i) {
        if(dist[i] > SEMI) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    solve(1);
    return 0;
}