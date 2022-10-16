#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > adj;
int dists[20001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dists[0] = 0;
    dists[1] = 0;
    deque<pair<int, int> > dq;
    dq.push_back({0, 1});
    while(!dq.empty()) {
        auto [cost, pos] = dq.front(); dq.pop_front();
        if(dists[pos] < cost) continue;
        for(auto next: adj[pos]) {
            int nc = dists[pos] + 1;
            int np = next;
            if(dists[np] > nc) {
                dists[np] = nc;
                dq.push_back({nc, np});
            }
        }
    }
    int min_val = *max_element(dists+1, dists+N+1);
    int idx = -1;
    int cnts = 0;
    for(int i = 1; i <= N; i++) {
        if(dists[i] == min_val) {
            if(idx == -1) {
                idx = i;
            }
            cnts++;
        }
    }
    cout << idx << " " << min_val << " " << cnts;
}