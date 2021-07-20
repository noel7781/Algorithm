#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> v;

struct segTree {
    int n;
    vector<ll> rangeSum;
    segTree(const vector<ll>& arr) {
        n = arr.size();
        rangeSum.resize(4*n);
        init(arr, 0, n-1, 1);
    }
    ll init(const vector<ll>& arr, int left, int right, int node) {
        if(left == right) return rangeSum[node] = arr[left];
        int mid = (left + right) / 2;
        return rangeSum[node] = init(arr, left, mid, node*2) + init(arr, mid+1, right, node*2+1);
    }
    ll query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left >nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }
    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    ll update(int index, ll newValue, int nodeLeft, int nodeRight, int node) {
        if(nodeLeft > index || index > nodeRight) return rangeSum[node];
        if(nodeLeft == nodeRight) return rangeSum[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeSum[node] = update(index, newValue, nodeLeft, mid, node*2) + update(index, newValue, mid+1, nodeRight, node*2+1);
    }
    ll update(int index, ll newValue) {
        return update(index, newValue, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    v.assign(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    struct segTree t(v);
    for(int i = 0; i < m+k; ++i) {
        ll com, n1, n2; cin >> com >> n1 >> n2;
        if(com ==1) {
            t.update(n1-1, n2);
        } else {
            cout << t.query(n1-1, n2-1) << "\n";
        }
    }
}