#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

int n; 
/*
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
*/

struct segTree {
    int n;
    vector<int> count;
    segTree(int size) {
        n = size;
        count.resize(n*4, 0);
    }

    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(nodeRight < left || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return count[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right ,nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }

    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }

    int update(int index, int newValue, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || nodeRight < index) return count[node];
        if(nodeLeft == nodeRight) return count[node] += newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return count[node] = update(index, newValue, nodeLeft, mid, node*2) +
                             update(index, newValue, mid+1, nodeRight, node*2+1);
    }

    int update(int index, int newValue) {
        return update(index, newValue, 0, n-1, 1);
    }
};


ull solve(vector<int>& v) {
    segTree t(1000000);
    ull ret = 0;
    for(int i = 0; i < n; ++i) {
        ret += t.query(v[i]+1, 999999);
        t.update(v[i], 1);
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        scanf("%d", &n);
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        printf("%llu\n", solve(v));
    }
}
