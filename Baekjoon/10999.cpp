#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> v;

struct segTree {
    int n;
    vector<ll> sum;
    vector<ll> lazy;
    segTree(const vector<ll>& v) {
        n = v.size();
        sum.assign(4*n, 0);
        lazy.assign(4*n, 0);
        init(v, 0, n-1, 1);
    }
    ll init(const vector<ll>& v, int left, int right, int node) {
        if(left == right) return sum[node] = v[left];
        int mid = (left + right) / 2;
        return sum[node] = init(v, left, mid, node*2) + init(v, mid+1, right, node*2+1);
    }

    void propagate(int nodeLeft, int nodeRight, int node) {
        if(lazy[node]) {
            sum[node] += (nodeRight - nodeLeft + 1) * lazy[node];
            if(nodeLeft != nodeRight) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    ll query(int left, int right, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) {
            return sum[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }
    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    ll update(int left, int right, ll value, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(right < nodeLeft || left > nodeRight) return sum[node];
//        if(nodeLeft == nodeRight) return sum[node] += value;
        if(left <= nodeLeft && nodeRight <= right) {
            sum[node] += (nodeRight - nodeLeft + 1) * value;
            if(nodeLeft != nodeRight) {
                lazy[node*2] += value;
                lazy[node*2+1] += value;
            }
            return sum[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        ll l_sum = update(left, right, value, nodeLeft, mid, node*2);
        ll r_sum = update(left, right, value, mid+1, nodeRight, node*2+1);
        return sum[node] = l_sum + r_sum;
    }
    ll update(int left, int right, ll value) {
        return update(left, right, value, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    v.assign(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    segTree t(v);
    for(int i = 0; i < m+k; ++i) {
        int p, q, r;  ll s;
        cin >> p;
        if(p == 1) {
            cin >> q >> r >> s;
            t.update(q, r, s);
        } else {
            cin >> q >> r;
            cout << t.query(q, r) << "\n";

        }
    }
}
