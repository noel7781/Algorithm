#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll psum[200001];
vector<int> org;
vector<int> sorted;
int N, M;
int get_index(int value) {
    return lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    ll ret = 0;
    org.resize(N); sorted.resize(N);
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        org[i] = y; sorted[i] = y;
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(),sorted.end()), sorted.end());
    for(int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c;
        u = get_index(org[u-1]); v = get_index(org[v-1]);
        if(u > v) swap (u, v);
        psum[u] += c;
        psum[v+1] -= c;
    }
    ll cur = psum[0];
    ret = psum[0];
    for(int i = 1; i <= 200000; i++) {
        cur += psum[i];
        ret = max(ret, cur);
    }
    cout << ret << "\n";
}