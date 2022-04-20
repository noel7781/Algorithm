#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, K;
vector<pii> orders;
int cache[101][301][301];
int solve(int pos, int l1, int l2) {
    if(pos >= N) return 0;
    int& ret = cache[pos][l1][l2];
    if(ret != -1) return ret;
    ret = 0;
    if(orders[pos].first <= l1 && orders[pos].second <= l2) {
        ret = max(ret, 1+solve(pos+1, l1-orders[pos].first, l2-orders[pos].second));
    }
    ret = max(ret, solve(pos+1, l1, l2));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M >> K;
    orders.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> orders[i].first >> orders[i].second;
    }
    cout << solve(0, M, K) << "\n";
    return 0;
}