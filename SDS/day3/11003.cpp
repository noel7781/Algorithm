#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> v;

struct segTree {
    int n;
    vector<int> rangeMin;
    segTree(const vector<int>& arr) {
        n = arr.size();
        rangeMin.resize(4*n);
        init(arr, 0, n-1, 1);
    }
    int init(const vector<int>& arr, int left, int right, int node) {
        if(left == right) return rangeMin[node] = arr[left];
        int mid = (left + right) / 2;
        return rangeMin[node] = min(init(arr, left, mid, node*2), init(arr, mid+1, right, node*2+1));
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return 1e9;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, nodeLeft, mid, node*2),
                   query(left, right, mid+1, nodeRight, node*2+1));
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    v.assign(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    struct segTree t(v);
    for(int i = 0; i < n; ++i) {
        int left = max(0, i - l + 1);
        cout << t.query(left, i) << " ";
    }
}