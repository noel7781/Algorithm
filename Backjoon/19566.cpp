#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll psum[200005];
ll comb(ll x) {
    return x*(x-1)/2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; ll K; cin >> N >> K;
    for(int i = 0; i < N; i++) {
        ll x; cin >> x;
        psum[i+1] = psum[i] + x - K;
    }
    map<ll, ll> m;
    for(int i = 1; i <= N; i++) {
        m[psum[i]]++;
    }
    ll ans = 0;
    ans += m[0];
    for(auto it = m.begin(); it != m.end(); it++) {
        ans += comb(it->second);
    }
    cout << ans << "\n";
}