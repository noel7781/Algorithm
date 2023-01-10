#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int n, m, k;

vector<vector<tiii> > v;

void solve() {
    int dp[101][10001];
    memset(dp, 0x3f, sizeof(dp));
    // 시간 비용 현재위치
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push(tiii(0, 0, 1));
    dp[0][0] = 0;
    int ret = -1;
    while(!pq.empty()) {
        tiii top = pq.top(); pq.pop();
        int cur_time = get<0>(top), cur_paid = get<1>(top), cur_pos = get<2>(top);
        if(cur_pos == n) {
            ret = cur_time;
            break;
        }
        if(cur_paid > m) continue;
        if(dp[cur_pos][cur_paid] < cur_time) continue;
        for(auto next: v[cur_pos]) {
            int next_pos = get<0>(next), next_time = cur_time + get<2>(next), next_paid = cur_paid + get<1>(next);
            if(next_paid > m) continue;
            if(dp[next_pos][next_paid] > next_time) {
                dp[next_pos][next_paid] = next_time;
                pq.push(tiii(next_time, next_paid, next_pos));
            }
        }
    }
    if(ret == -1) {
        cout << "Poor KCM\n";
    } else {
        cout << ret << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m >> k;
        v.resize(n+1);
        for(int i = 0; i < k; ++i) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            v[a].push_back(tiii(b, c, d));
        }
        solve();
    }
}
