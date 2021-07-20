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
    vector<int> init(const vector<int>& arr, int left, int right, int node) {
        if(left == right) {
            rangeVec[node].push_back(arr[left]);
            return rangeVec[node];
        }
        int mid = (left + right) / 2;
        vector<int> l = init(arr, left, mid, node*2);
        vector<int> r = init(arr, mid+1, right, node*2+1);
        rangeVec[node].insert(rangeVec[node].end(), l.begin(), l.end());
        rangeVec[node].insert(rangeVec[node].end(), r.begin(), r.end());
        return rangeVec[node];
    }
    vector<int> query(int left, int right, int nodeLeft, int nodeRight, int node) {
        vector<int> v;
        if(left > nodeRight || right < nodeLeft) return v;
        if(left <= nodeLeft && nodeRight <= right) {
            return rangeVec[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        vector<int> l = query(left, right, nodeLeft, mid, node*2);
        vector<int> r = query(left, right, mid+1, nodeRight, node*2 + 1);
        v.insert(v.end(), l.begin(), l.end());
        v.insert(v.end(), r.begin(), r.end());
        return v;
    }
    vector<int> query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    int query(int left, int right, int q) {
        vector<int> ret = query(left, right);
        return ret[q];
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
        cout << t.query(a-1, b-1, n-1) << "\n";
    }
}
