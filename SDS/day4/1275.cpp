#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
struct segTree {
    int n;
    vector<ll> rangeSum;
    segTree(vector<ll>& arr) {
        n = arr.size();
        rangeSum.resize(n*4);
        init(arr, 0, n-1, 1);
    }
    ll init(vector<ll>& arr, int left, int right, int node) {
        if(left == right) return rangeSum[node] = arr[left];
        int mid = (left + right) / 2;
        return rangeSum[node] = init(arr, left, mid, node*2) + init(arr, mid+1, right, node*2+1);
    }
    ll query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return query(left, right ,nodeLeft, mid, node*2) + query(left, right ,mid+1, nodeRight, node*2+1);
    }
    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    ll update(int i, int newV, int nodeLeft, int nodeRight, int node) {
        if(i < nodeLeft || i > nodeRight) return rangeSum[node];
        if(nodeLeft == nodeRight) return rangeSum[node] = newV;
        int mid = (nodeLeft + nodeRight) >> 1;
        return rangeSum[node] = update(i, newV, nodeLeft, mid, node*2) +update(i, newV, mid+1, nodeRight, node*2+1);
    }
    ll update(int i, int newV) {
        return update(i, newV, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for(auto &it: v) {
        cin >> it;
    }
    struct segTree t(v);
    for(int i = 0; i < q; ++i) {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << t.query(x-1, y-1) << "\n";
        t.update(a-1, b);
    }
}