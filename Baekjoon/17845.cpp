#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<pii> V;
int cache[10001][1001];
int solve(int left, int pos) {
    if(pos == K) return 0;
    int& ret = cache[left][pos];
    if(ret != -1) return ret;
    ret = 0;
    if(left >= V[pos].second) ret = max(ret, solve(left-V[pos].second, pos+1) + V[pos].first);
    ret = max(ret, solve(left, pos+1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    V.resize(K);
    for(auto &it: V){ 
        cin >> it.first >> it.second;
    }
    cout << solve(N, 0) << "\n";
}