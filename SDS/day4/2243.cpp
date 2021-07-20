#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX_NUM = 1000010;
int n;

struct segTree {
    int n;
    vector<int> count;
    segTree(int k) {
        n = k;
        count.resize(4*n);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || nodeLeft > right) return 0;
        if(left <= nodeLeft && nodeRight <= right) return count[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return query(left, right, nodeLeft, mid, node*2) + query(left, right ,mid+1, nodeRight, node*2+1);
    }
    int query(int right) {
        return query(0, right, 0, n-1, 1);
    }
    int update(int index, int value, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || index > nodeRight) return count[node];
        if(nodeLeft == nodeRight) return count[node] += value;
        int mid = (nodeLeft + nodeRight) / 2;
        return count[node] = update(index, value, nodeLeft, mid, node*2) + update(index, value, mid+1, nodeRight, node*2+1);
    }
    int update(int index, int value) {
        return update(index, value, 0, n-1, 1);
    }
};

int findKth(segTree& t, int k) {
    int leftCount = 0;
    int lo = -1, hi = MAX_NUM+1;
    while(lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if(t.query(mid) >= k) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("test.in", "r", stdin);
    struct segTree t(MAX_NUM);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b;
        if(a == 2) {
            cin >> c;
            t.update(b, c);
        } else {
            int k = findKth(t, b);
            t.update(k, -1);
            cout << k << "\n";
        }
    }
}