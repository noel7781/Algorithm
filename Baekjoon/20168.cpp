#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int N, M, A, B, C;
vector<vector<pii> > adj;
int dist[1001][100];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> A >> B >> C;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int n1, n2, cs; cin >> n1 >> n2 >> cs;
        adj[n1].push_back({n2, cs});
        adj[n2].push_back({n1, cs});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0][A] = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    // 여태까지 cost, max cost, pos
    pq.push({0, 0, A});
    while(!pq.empty()) {
        auto [curr_cost, max_cost, curr_pos] = pq.top(); pq.pop();
        if(dist[max_cost][curr_pos] < curr_cost || curr_cost > C) continue;
        for(auto next: adj[curr_pos]) {
            int next_cost = curr_cost + next.second;
            int next_pos = next.first;
            int next_max = max(max_cost, next.second);
            if(dist[next_max][next_pos] < next_cost || next_cost > C) continue;
            dist[next_max][next_pos] = next_cost;
            pq.push({next_cost, next_max, next_pos});
        }
    }
    int ret = -1;
    for(int j = 1; j <= 1000; j++) {
        if(dist[j][B] <= C) {
            ret = j;
            break;
        }
    }
    cout << ret << "\n";
}