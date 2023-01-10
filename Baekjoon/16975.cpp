#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<ll> v;

struct segTree {
    int n;
    vector<ll> lazy;
    vector<ll> arr;
    segTree(vector<ll>& v) {
        n = v.size();
        lazy.assign(4*n, 0);
        arr.assign(4*n, 0);
        init(v, 0, n-1, 1);
    }
    ll init(vector<ll>& v, int left, int right, int node) {
        if(left == right) return arr[node] = v[left];
        int mid = (left + right) / 2;
        ll ret1 = init(v, left, mid, node*2);
        ll ret2 = init(v, mid+1, right, node*2+1);
        return arr[node] = (ret1 != 0) ? ret1 : ret2;
    }
    void propagate(int nodeLeft, int nodeRight, int node) {
        if(lazy[node]) {
            //arr[node] += (nodeRight - nodeLeft + 1) * lazy[node];
            if(nodeLeft != nodeRight) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
                arr[node] = 0;
            } else {
                arr[node] += (nodeRight - nodeLeft + 1) * lazy[node];
            }
            lazy[node] = 0;
        }
    }

    ll query(int idx, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(idx > nodeRight || idx < nodeLeft) return 0;
        if(nodeLeft == nodeRight) return arr[node];
        int mid = (nodeLeft + nodeRight) / 2;
        ll ret1 = query(idx, nodeLeft, mid, node*2); 
        ll ret2 = query(idx, mid+1, nodeRight, node*2+1);
        return ret1 != 0 ? ret1 : ret2;
    }

    ll query(int idx) {
        return query(idx, 0, n-1, 1);
    }

    ll update(int left, int right, ll value, int nodeLeft, int nodeRight, int node) {
        propagate(nodeLeft, nodeRight, node);
        if(left > nodeRight || right < nodeLeft) return arr[node];
        if(left <= nodeLeft && nodeRight <= right) {
            //arr[node] += (nodeRight - nodeLeft + 1) * value;
            if(nodeLeft != nodeRight) {
                lazy[node*2] += value;
                lazy[node*2+1] += value;
                arr[node] = 0;
            } else {
                arr[node] += (nodeRight - nodeLeft + 1) * value;
            }
            return arr[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        ll ret1 = update(left, right, value, nodeLeft, mid, node*2); 
        ll ret2 = update(left, right, value, mid+1, nodeRight, node*2+1);
        return ret1 != 0 ? ret1 : ret2;

    }

    ll update(int left, int right, ll value) {
        return update(left, right, value, 0, n-1, 1);
    }
    
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.assign(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    segTree t(v);
    int m; cin >> m;
    while(m--) {
        int p, q, r; ll s;
        cin >> p;
        if(p == 1) {
            cin >> q >> r >> s;
            t.update(q, r, s);
        } else {
            cin >> q;
            cout << t.query(q) << "\n";
        }
    }
}
