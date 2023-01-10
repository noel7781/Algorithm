#include <bits/stdc++.h>
using namespace std;
int N, K, W;
vector<int> build_time;
vector<vector<int> > adj;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        build_time.clear();
        adj.clear();
        cin >> N >> K;
        build_time.resize(N);
        adj.resize(N);
        vector<int> ins(N, 0);
        vector<int> dists(N, 0);
        for(auto &it: build_time) cin >> it;
        for(int i = 0; i < K; i++) {
            int P, Q; cin >> P >> Q;
            P -= 1; Q -= 1;
            adj[P].push_back(Q);
            ins[Q]++;
        }
        cin >> W;
        queue<int> q;
        int ret = 0;
        for(int i = 0; i < N; i++) {
            if(!ins[i]) {
                q.push(i);
                dists[i] = build_time[i];
            }
        }
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(auto next: adj[now]) {
                dists[next] = max(dists[next], dists[now] + build_time[next]);
                ins[next]--;
                if(!ins[next]) {
                    q.push(next);
                }
            }
        }
        cout << dists[W-1] << "\n";
    }
}