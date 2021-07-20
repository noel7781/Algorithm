#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
vector<vector<pii> > v;

int V, E;
int s;

void solve() {
    vector<int> d(V+1, 1e9);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    d[s] = 0;
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        int c_dist = now.first, pos = now.second;
        if(d[pos] < c_dist) continue;
        for(int i = 0; i < v[pos].size(); ++i) {
            int next = v[pos][i].first;
            int next_d = c_dist + v[pos][i].second;
            if(d[next] > next_d) {
                pq.push(make_pair(next_d, next));
                d[next] = next_d;
            }
        }
    }
    for(int i = 1; i <= V; ++i) {
        if(d[i] == 1e9) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    cin >> s;
    v.assign(V+1, vector<pii>());
    for(int i = 0; i < E; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    solve();
}