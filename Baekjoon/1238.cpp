#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, X;
vector<vector<pii> > adj;
vector<vector<pii> > rev;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> X;
    adj.resize(N+1);
    rev.resize(N+1);
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        rev[b].push_back({a, c});
    }
    vector<int> dists1(N+1, 1e9);
    vector<int> dists2(N+1, 1e9);
    dists1[X] = 0;
    dists2[X] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, X});
    while(!pq.empty()) {
        auto [cur_cost, cur_pos] = pq.top(); pq.pop();
        if(dists1[cur_pos] < cur_cost) continue;
        for(const auto& next_place: adj[cur_pos]) {
            int next_cost = cur_cost + next_place.second;
            int next_pos = next_place.first;
            if(dists1[next_pos] > next_cost) {
                dists1[next_pos] = next_cost;
                pq.push({next_cost, next_pos});
            }
        }
    }
    pq.push({0, X});
    while(!pq.empty()) {
        auto [cur_cost, cur_pos] = pq.top(); pq.pop();
        if(dists2[cur_pos] < cur_cost) continue;
        for(const auto& next_place: rev[cur_pos]) {
            int next_cost = cur_cost + next_place.second;
            int next_pos = next_place.first;
            if(dists2[next_pos] > next_cost) {
                dists2[next_pos] = next_cost;
                pq.push({next_cost, next_pos});
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        ret = max(ret, dists1[i] + dists2[i]);
    }

    cout << ret << "\n";
}