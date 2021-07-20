#include <iostream>
#include <vector>

using namespace std;

struct fenwickTree {
    vector<int> tree;
    fenwickTree(int n): tree(n+1) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void update(int pos, int v) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += v;
            pos += (pos & -pos);
        }
    }
};

int findKth(fenwickTree& t, int k) {
    int lo = -1, hi = 2000001;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(t.sum(mid) >= k) {
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
    int n; cin >> n;
    fenwickTree t(2000001);
    while(n--) {
        int a, b; cin >> a >> b;
        if(a==1) {
            t.update(b, 1);
        } else {
            int er = findKth(t, b);
            t.update(er, -1);
            cout << er << "\n";
        }
    }
}
