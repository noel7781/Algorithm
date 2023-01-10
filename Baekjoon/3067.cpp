#include <bits/stdc++.h>
using namespace std;
int cache[10001][21];
int N, M;
vector<int> V;
int solve(int left, int last) {
    if(left < 0) return 0;
    if(left == 0) return 1;
    int& ret = cache[left][last];
    if(ret != -1) return ret;
    ret = 0;
    for(int j = last; j < N; j++) {
        ret += solve(left-V[j], j);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        V.clear();
        memset(cache, -1, sizeof(cache));
        cin >> N; V.resize(N);
        for(auto &it: V) cin >> it;
        cin >> M;
        cout << solve(M, 0) << "\n";
    }
}