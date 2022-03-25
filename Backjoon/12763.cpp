#include <bits/stdc++.h>
using namespace std;
struct Info {
    int nxt;
    int time;
    int cost;
};
struct comp {
    bool operator()(Info& A, Info& B) {
        return A.cost > B.cost;
    }
};
int N, T, M, L;
vector<vector<Info> > adj;
int solve() {
    int ret = -1;
    vector<vector<int> > dists(N+1, vector<int>(T+1, 1e9));
    dists[1][T] = 0;
    priority_queue<Info, vector<Info>, comp> pq;
    pq.push({1, T, 0});
    while(!pq.empty()) {
        auto [curr_pos, left_time, paid] = pq.top(); pq.pop();
        if(curr_pos == N) {
            return paid;
        }
        if(dists[curr_pos][left_time] < paid) continue;
        for(auto &[next_pos, need_time, need_pay]: adj[curr_pos]) {
            if(need_time <= left_time && paid+need_pay <= M && dists[next_pos][left_time-need_time] > paid+need_pay) {
                dists[next_pos][left_time-need_time] = paid+need_pay;
                pq.push({next_pos, left_time-need_time, paid+need_pay});
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T >> M >> L;
    adj.resize(N+1);
    for(int i = 0; i < L; i++) {
        int p1, p2, t, c; cin >> p1 >> p2 >> t >> c;
        adj[p1].push_back({p2, t, c});
        adj[p2].push_back({p1, t, c});
    }
    cout << solve() << "\n";
}