#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<pii> > adj;
int dists[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    for(int i = 0; i < N-1; i++) {
        int p1, p2, d; cin >> p1 >> p2 >> d;
        adj[p1].push_back({p2, d});
        adj[p2].push_back({p1, d});
    }
    for(int i = 0; i < M; i++) {
        memset(dists, 0x3f, sizeof(dists));
        int s, e; cin >> s >> e;
        queue<int> q;
        q.push(s);
        dists[s] = 0;
        while(!q.empty()) {
            auto now = q.front(); q.pop();
            if(now == e) {
                cout << dists[e] << "\n";
                break;
            }
            for(const auto& next: adj[now]) {
                int next_pos = next.first, next_cost = next.second + dists[now];
                if(dists[next_pos] > next_cost) {
                    dists[next_pos] = next_cost;
                    q.push(next_pos);
                }
            }
        }
    }
}