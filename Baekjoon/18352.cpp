#include <bits/stdc++.h>
using namespace std;
int N, M, K, X;
int dists[300001];
vector<vector<int> > adj;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M >> K >> X;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int p, q; cin >> p >> q;
        adj[p].push_back(q);
    }
    queue<int> q;
    q.push(X);
    dists[X] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(const auto& next: adj[now]) {
            if(dists[next] > dists[now] + 1) {
                dists[next] = dists[now] + 1;
                q.push(next);
            }
        }
    }
    bool is_print = false;
    for(int i = 1; i <= N; i++) {
        if(dists[i] == K) {
            is_print = true;
            cout << i << "\n";
        }
    }
    if(!is_print) {
        cout << -1 << "\n";
    }
}