#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segTree {
    int n;
    vector<vector<int> > rangeVec;
    segTree(const vector<int>& arr) {
        n = arr.size();
        rangeVec.assign(4*n, vector<int>());
        init(arr, 0, n-1, 1);
    }
    vector<int>& init(const vector<int>& arr, int left, int right, int node) {
        if(left == right) {
            rangeVec[node].push_back(arr[left]);
            return rangeVec[node];
        }
        int mid = (left + right) / 2;
        vector<int> l = init(arr, left, mid, node*2);
        vector<int> r = init(arr, mid+1, right, node*2+1);
        auto lit = l.begin();
        auto rit = r.begin();
        while(lit != l.end() && rit != r.end()) {
            if(*lit > *rit) {
                rangeVec[node].push_back(*rit);
                rit++;
            } else {
                rangeVec[node].push_back(*lit);
                lit++;
            }
        }
        while(lit != l.end()) {
            rangeVec[node].push_back(*lit);
            lit++;
        }
        while(rit != r.end()) {
            rangeVec[node].push_back(*rit);
            rit++;
        }
        return rangeVec[node];
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node, int k) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) {
            return upper_bound(rangeVec[node].begin(), rangeVec[node].end(), k) - rangeVec[node].begin();
        }
        int mid = (nodeLeft + nodeRight) / 2;
        int l = query(left, right, nodeLeft, mid, node*2, k);
        int r = query(left, right, mid+1, nodeRight, node*2 + 1, k);
        return l+r;
    }
    int query(int left, int right, int k) {
        int ret = query(left, right, 0, n-1, 1, k);
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int size, q; cin >> size >> q;
    vector<int> arr(size);
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    struct segTree t(arr);
    while(q--) {
        int a, b, n; cin >> a >> b >> n;
        int lo = -1e9-1, hi = 1e9;
        while(lo+1 < hi) {
            int mid = (lo+hi)>>1;
            if(t.query(a-1, b-1, mid) >= n) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << hi << "\n";
    }
}

