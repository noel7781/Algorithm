#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, T;
vector<pii> V;
int cache[101][10001];
int solve(int pos ,int left) {
    if(pos == N) return 0;
    int& ret = cache[pos][left];
    if(ret != -1) return ret;
    ret = solve(pos+1, left);
    if(V[pos].first <= left) ret = max(ret, V[pos].second + solve(pos+1, left-V[pos].first));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> T;
    V.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    cout << solve(0, T) << "\n";
}