#include <iostream>
#include <vector>

using namespace std;

#define INF 1234567809

struct segTree {
    int n;
    vector<int> rangeMin;
    segTree(const vector<int>& arr) {
        n = arr.size();
        rangeMin.resize(4*n);
        init(arr, 0, n-1, 1);
    }
    int init(const vector<int>& arr, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = arr[left];
        int mid = (left + right) /  2;
        return rangeMin[node] = min(init(arr, left, mid, node*2), init(arr, mid+1, right, node*2 + 1));
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(right < nodeLeft || left > nodeRight) return INF;
        if(left <= nodeLeft && nodeRight <= right) {
            return rangeMin[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, nodeLeft, mid, node*2), query(left, right, mid+1, nodeRight, node*2 + 1));
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int size, q;
    cin >> size >> q;
    vector<int> arr(size);
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    struct segTree t(arr);
    while(q--) {
        int a, b; cin >> a >> b;
        cout << t.query(a-1, b-1) << "\n";
    }
}
