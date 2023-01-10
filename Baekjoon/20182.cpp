#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, A, B, C;
vector<vector<pii> > adj;
int dist[100001];
bool check(int thr) {
    memset(dist, 0x3f, sizeof(dist));
    dist[A] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    // 여태까지 cost, pos
    pq.push({0, A});
    while(!pq.empty()) {
        auto [curr_cost, curr_pos] = pq.top(); pq.pop();
        if(dist[curr_pos] < curr_cost) continue;
        for(auto& next: adj[curr_pos]) {
            int next_cost = curr_cost + next.second;
            int next_pos = next.first;
            if(next.second <= thr && dist[next_pos] > next_cost) {
                dist[next_pos] = next_cost;
                pq.push({next_cost, next_pos});
            }
        }
    }
    return dist[B] <= C;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> A >> B >> C;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int n1, n2, cs; cin >> n1 >> n2 >> cs;
        adj[n1].push_back({n2, cs});
        adj[n2].push_back({n1, cs});
    }
    int lo = 0, hi = 21;
    while(lo+1 < hi) {
        int mid = (lo+hi)>>1;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    int ret = -1;
    if(hi != 21) ret = hi;
    cout << ret << "\n"; 
}