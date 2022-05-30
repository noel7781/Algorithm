#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
int S;
int dp[2003][2003];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    memset(dp, 0x3f, sizeof(dp));
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, 1, 0});
    dp[1][0] = 0;
    while(!pq.empty()) {
        auto [cur_time, cur_pos, cur_clip] = pq.top(); pq.pop();
        if(cur_pos == S) break;
        if(dp[cur_pos][cur_clip] < cur_time) continue;
        int next_time = cur_time + 1;
        int next_pos = cur_pos + cur_clip;
        if(next_pos <= 2*S) {
            if(dp[next_pos][cur_clip] > next_time) {
                dp[next_pos][cur_clip] = next_time;
                pq.push({next_time, next_pos, cur_clip});
            }
        }
        next_pos = cur_pos - 1;
        if(next_pos >= 1) {
            if(dp[next_pos][cur_clip] > next_time) {
                dp[next_pos][cur_clip] = next_time;
                pq.push({next_time, next_pos, cur_clip});
            }
        }
        next_pos = cur_pos;
        int next_clip = next_pos;
        if(next_pos != cur_clip) {
            if(dp[next_pos][next_clip] > next_time) {
                dp[next_pos][next_clip] = next_time;
                pq.push({next_time, next_pos, next_clip});
            }
        }
    }
    int ret = 1e9;
    for(int i = 0; i <= 2002; i++) {
        ret = min(ret, dp[S][i]);
    }
    cout << ret << "\n";

}