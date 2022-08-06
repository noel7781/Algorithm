#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int C, N;
vector<pii> V;
int cache[1001][21];
int solve(int c, int pos) {
    if(c >= C) return 0;
    if(pos >= N) return 1e9;
    int& ret = cache[c][pos];
    if(ret != -1) return ret;
    ret = 1e9;
    ret = min(ret, V[pos].first + solve(c+V[pos].second, pos));
    ret = min(ret, solve(c, pos+1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> C >> N;
    V.resize(N);
    for(auto &it: V) cin >> it.first >> it.second;
    cout << solve(0, 0) << "\n";
    return 0;
}