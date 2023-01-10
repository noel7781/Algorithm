#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, e;
int v1, v2;
vector<vector<pii> > v;

int solve(int s, int d) {
    vector<int> dist(n+1, 1e8);
    priority_queue<pii, vector<pii>, greater<pii> > pq; // dist, idx
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first, now = pq.top().second;
        pq.pop();
        if(dist[now] < cost) continue;
        for(int i = 0; i < v[now].size(); ++i) {
            int next = v[now][i].first;
            int nextDist = cost + v[now][i].second;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return dist[d];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    v.resize(n+1);
    for(int i = 0; i < e; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    int d = solve(v1, v2);
    int ret = min(solve(1, v1) + solve(v2, n) + d, solve(1, v2) + solve(v1, n) + d);
    if(ret >= 1e8) cout << "-1" << "\n";
    else cout << ret << "\n";
}