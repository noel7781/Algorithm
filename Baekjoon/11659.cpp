#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int size, cnt;
vector<int> arr;

struct RSQ {
    int n;
    vector<int> rangeSum;
    RSQ(const vector<int>& array) {
        n = array.size();
        rangeSum.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeSum[node] = array[left];
        int mid = (left + right) / 2;
        int leftSum = init(array, left, mid, node*2);
        int rightSum = init(array, mid+1, right, node*2 + 1);
        return rangeSum[node] = leftSum + rightSum;
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left)
            return 0;
        if(left <= nodeLeft && nodeRight <= right)
            return rangeSum[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node*2, nodeLeft, mid) + query(left, right, node*2 + 1, mid+1, nodeRight);
    }
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> size >> cnt;
    arr.assign(size, 0);
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    struct RSQ segtree(arr);
    while(cnt--) {
        int start, end; cin >> start >> end;
        cout << segtree.query(start-1, end-1) << "\n";
    }
}
