#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q;
ll tree[int(2*1e6+1)];
void add(ll i, ll x) {
    for(; i <= N; i += i&-i) {
        tree[i] += x;
    }
}
ll sum(ll i) {
    ll ret = 0;
    for(; i > 0; i -= i&-i) {
        ret += tree[i];
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < Q; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            add(x, y);
        } else {
            cout << sum(y) - sum(x-1) << "\n";
        }
    }
}