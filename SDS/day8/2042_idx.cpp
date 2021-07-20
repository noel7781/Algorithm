#include <iostream>
#include <vector>

#define PIV (1 << 20)

using namespace std;

typedef long long ll;

ll tree[PIV*2];

void update(int n, ll v) {
    n += PIV;
    tree[n] = v;
    n /= 2;
    while(n > 0) {
        tree[n] = tree[n*2] + tree[n*2+1];
        n /= 2;
    }
}

ll query(int l, int r) {
    l += PIV;
    r += PIV;
    ll ret = 0;
    while(l <= r) {
        if(l % 2 == 1) ret += tree[l++];
        if(r % 2 == 0) ret += tree[r--];
        l /= 2; r /= 2;
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> v(n, 0);
    for(auto &it: v) cin >> it;
    for(int i = 0; i < n; ++i) {
        update(i, v[i]);
    }
    for(int i = 0; i < m+k; ++i) {
        int a, b; ll c; cin >> a >> b >> c;
        if(a == 1) {
            b--;
            update(b, c);
        } else {
            b--; c--;
            cout << query(b, c) << "\n";
        }
    }
}