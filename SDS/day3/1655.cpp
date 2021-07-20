#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int MAX_SIZE = 20001;

struct segTree {
    int n;
    vector<int> cnt;
    segTree(int num) {
        n = num;
        cnt.resize(4*n, 0);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return cnt[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        return (query(left, right, nodeLeft, mid, node*2) +
                   query(left, right, mid+1, nodeRight, node*2+1));
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    int update(int index, int newValue, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || nodeRight < index) return cnt[node];
        if(nodeLeft == nodeRight) return cnt[node] += newValue;
        int mid = (nodeLeft + nodeRight) >> 1;
        return cnt[node] = update(index, newValue, nodeLeft, mid, node*2) + update(index, newValue, mid+1, nodeRight, node*2+1);
    }
    int update(int index, int newValue) {
        return update(index, newValue, 0, n-1, 1);
    }

};

int findKth(segTree& t, int m) {
    int left= -1, right = MAX_SIZE;
    int target = (m+1)/2;
    while(left+1 < right) {
        int mid = (left + right) >> 1;
        int count = t.query(0, mid);
        if(count >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.assign(n, 0);
    struct segTree t(MAX_SIZE);
    int idx = 1;
    for(int i=  0; i < n; ++i) {
        int num; cin >> num;
        t.update(num+10000, 1);
        cout << findKth(t, idx++) - 10000 << "\n";
    }
}