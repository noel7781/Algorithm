#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<int> > adj;
vector<int> dists;
vector<int> trusts;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    queue<pii> q;
    adj.resize(N+1);
    dists.resize(N+1, -1);
    trusts.resize(N+1, 0);
    for(int i = 1; i <= N; i++) {
        int fr = -1;
        while(true) {
            cin >> fr;
            if(fr == 0) break;
            adj[i].push_back(fr);
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int p; cin >> p;
        dists[p] = 0; trusts[p] = 1;
        q.push({p, 0});
    }
    while(!q.empty()) {
        auto [now, time] = q.front(); q.pop();
        for(const auto& next: adj[now]) {
            if(dists[next] == -1) {
                trusts[next]++;
                if(trusts[next] >= (adj[next].size()+1) / 2) {
                    dists[next] = time+1;
                    q.push({next, time+1});
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        cout << dists[i] << " ";
    }
    cout << "\n";
    return 0;
}