#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int cache[1500001];
vector<pii> V;
int solve(int pos) {
    if(pos >= N) return 0;
    int& ret = cache[pos];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, solve(pos+1));
    if(V[pos].first + pos <= N) ret = max(ret, V[pos].second + solve(pos+V[pos].first));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    V.resize(N);
    for(auto &it: V) cin >> it.first >> it.second;
    cout << solve(0);
}