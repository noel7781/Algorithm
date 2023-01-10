#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;
int size, edit, cnt;
vector<ll> arr;

struct RSQ {
    int n;
    vector<ll> rangeSum;
    RSQ(const vector<ll>& array) {
        n = array.size();
        rangeSum.resize(n*4);
        init(array, 0, n-1, 1);
    }
    ll init(const vector<ll>& array, int left, int right, int node) {
        if(left == right)
            return rangeSum[node] = array[left];
        int mid = (left + right) / 2;
        ll leftSum = init(array, left, mid, node*2);
        ll rightSum = init(array, mid+1, right, node*2 + 1);
        return rangeSum[node] = leftSum + rightSum;
    }
    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left)
            return 0;
        if(left <= nodeLeft && nodeRight <= right)
            return rangeSum[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node*2, nodeLeft, mid) + query(left, right, node*2 + 1, mid+1, nodeRight);
    }
    ll query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
    ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index)
            return rangeSum[node];
        if(nodeLeft == nodeRight)
            return rangeSum[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeSum[node] = update(index, newValue, node*2, nodeLeft, mid) + update(index, newValue, node*2 + 1, mid+1, nodeRight);
    }
    ll update(int index, ll newValue) {
        return update(index, newValue, 1, 0, n-1);
    }
};

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> size >> edit >> cnt;
    arr.assign(size, 0);
    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    struct RSQ segtree(arr);
    int t_cnt = edit + cnt;
    while(t_cnt--) {
        ll judge, start, end; cin >> judge >> start >> end;
        if(judge == 1)
            segtree.update(start-1, end);
        if(judge == 2)
            cout << segtree.query(start-1, end-1) << "\n";
    }
}
