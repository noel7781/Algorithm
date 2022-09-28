#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int V, E, P;
vector<vector<pii> > adj;
int d1[5001];
int d2[5001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> P;
    adj.resize(V+1);
    for(int i = 0; i < E; i++) {
        int p1, p2, d; cin >> p1 >> p2 >> d;
        adj[p1].push_back({p2, d});
        adj[p2].push_back({p1, d});
    }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    d1[1] = 0; d2[P] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [cd, cp] = pq.top(); pq.pop();
        if(d1[cp] < cd) continue;
        for(const auto next: adj[cp]) {
            int nd = cd + next.second;
            int np = next.first;
            if(d1[np] > nd) {
                d1[np] = nd;
                pq.push({nd, np});
            }
        }
    }
    pq = {};
    pq.push({0, P});
    while(!pq.empty()) {
        auto [cd, cp] = pq.top(); pq.pop();
        if(d2[cp] < cd) continue;
        for(const auto next: adj[cp]) {
            int nd = cd + next.second;
            int np = next.first;
            if(d2[np] > nd) {
                d2[np] = nd;
                pq.push({nd, np});
            }
        }
    }

    if(d1[P] + d2[V] == d1[V]) {
        cout << "SAVE HIM";
    } else {
        cout << "GOOD BYE";
    }
}