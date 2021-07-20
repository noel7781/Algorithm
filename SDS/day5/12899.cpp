#include <iostream>
#include <vector>

#define MAX 2000001

using namespace std;

struct segTree {
    int n;
    vector<int> cnt;
    segTree(int k) {
        n = k;
        cnt.resize(4*n);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return cnt[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return query(left, right, nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }
    int query(int right) {
        return query(1, right, 0, n-1, 1);
    }
    int update(int i, int v, int nodeLeft, int nodeRight, int node) {
        if(i < nodeLeft || i > nodeRight) return cnt[node];
        if(nodeLeft == nodeRight) return cnt[node] += v;
        int mid = (nodeLeft + nodeRight) >> 1;
        return cnt[node] = update(i, v, nodeLeft, mid, node*2) + update(i, v, mid+1, nodeRight, node*2+1);
    }
    int update(int i, int v) {
        return update(i, v, 0, n-1, 1);
    }
};

int getKth(segTree& t, int k) {
    int lo = 0, hi = 2000000;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
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
    segTree t(MAX);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int q, num; cin >> q >> num;
        if(q == 1) t.update(num, 1);
        else {
            int p = getKth(t, num);
            cout << p << "\n";
            t.update(p, -1);
        }
    }
}