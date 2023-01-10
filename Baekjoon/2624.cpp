#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int cache[10001][101];
int T, K;
vector<pii> V;
int solve(int left, int pos) {
    if(left == 0) return 1;
    if(pos >= K || left < 0) return 0;
    int& ret = cache[left][pos];
    if(ret != -1) return ret;
    ret = 0;
    for(int k = 0; k <= V[pos].second; k++) {
        ret += solve(left - V[pos].first * k, pos+1);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> T >> K;
    V.resize(K);
    for(auto &it: V) cin >> it.first >> it.second;
    int ans = solve(T, 0);
    cout << ans;
}