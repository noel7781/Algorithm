#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct segTree {
    int n;
    vector<ll> sum;
    vector<ll> lazy;
    segTree(vector<ll>& v) {
        n = v.size();
        sum.resize(4*n);
        lazy.resize(4*n);
        init(v, 0, n-1, 1);
    }
    void propagate(int left, int right, int node) {
        if(lazy[node]) {
            sum[node] += (right - left + 1) * lazy[node];
            if(left != right) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    ll init(vector<ll>& v, int left, int right, int node) {
        if(left == right) return sum[node] = v[left];
        int mid = (left + right) >> 1;
        return sum[node] = init(v, left, mid, node*2) + init(v, mid+1, right, node*2+1);
    }
    ll query(int left, int right, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return sum[node];
        int mid = (nodeLeft +nodeRight) >> 1;
        return query(left, right, nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }
    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }

    ll update(int left, int right, ll v, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(left > nodeRight || nodeRight < left) return sum[node];
        if(left <= nodeLeft && nodeRight <= right) {
            sum[node] += (nodeRight - nodeLeft + 1) * v;
            if(left != right) {
                lazy[node*2] += v;
                lazy[node*2+1] += v;
            }
            return sum[node];
        }
        int mid = (nodeLeft +nodeRight) >> 1;
        ll ret1 = update(left, right, v, nodeLeft, mid, node*2);

        ll ret2 = update(left, right, v, mid+1, nodeRight, node*2+1);
        return sum[node] = ret1 + ret2;
    }
    ll update(int l, int r, ll v) {
        return update(l, r, v, 0, n-1, 1);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> v(n, 0);
    for(auto &it: v){
        cin >> it;
    }
    struct segTree t(v);
    for(int i = 0; i < m+k; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) {
            ll d; cin >> d;
            t.update(b-1, c-1, d);
        } else {
            cout << t.query(b-1, c-1) << "\n";
        }
    }
}