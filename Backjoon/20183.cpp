#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll, ll> pii;
ll N, M, A, B, C;
vector<vector<pii> > adj;
ll dist[100001];
bool check(ll thr) {
    // for(int i = 1; i <= N; i++) dist[i] = 1e9;
    memset(dist, 0x3f, sizeof(dist));
    dist[A] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    // 여태까지 cost, pos
    pq.push({0, A});
    while(!pq.empty()) {
        auto [curr_cost, curr_pos] = pq.top(); pq.pop();
        if(dist[curr_pos] < curr_cost) continue;
        for(auto& next: adj[curr_pos]) {
            ll next_cost = curr_cost + next.second;
            ll next_pos = next.first;
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
        ll n1, n2, cs; cin >> n1 >> n2 >> cs;
        adj[n1].push_back({n2, cs});
        adj[n2].push_back({n1, cs});
    }
    ll lo = 0, hi = C+1;
    while(lo+1 < hi) {
        ll mid = (lo+hi)>>1;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    ll ret = -1;
    if(hi != C+1) ret = hi;
    cout << ret << "\n"; 
}