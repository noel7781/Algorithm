#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct fwTree {
    vector<ll> tree;
    fwTree(vector<ll> arr) {
        tree.assign(arr.size() + 1, 0);
        for(int i = 0; i < arr.size(); ++i) {
            update(i, arr[i]);
        }
    }
    ll sum(int pos) {
        ++pos;
        ll ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void update(int pos, ll v) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += v;
            pos += (pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> v(n, 0);
    for(auto &it: v) cin >> it;
    fwTree t(v);
    for(int i = 0; i < m+k; ++i) {
        int a, b; ll c; cin >> a >> b >> c;
        if(a == 1) {
            b--;
            ll u_v = c - (t.sum(b) - t.sum(b-1));
            t.update(b, u_v);
        } else {
            b--; c--;
            cout << t.sum(c) - t.sum(b-1) << "\n";
        }
    }
}