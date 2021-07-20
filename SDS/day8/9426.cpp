#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n, k;

struct fwTree {
    vector<int> tree;
    fwTree(int n) {
        tree.assign(n + 1, 0);
    }
    int query(int pos) {
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

ll Kth(fwTree& t, int cnt) {
    int lo = -1, hi = 65536;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        // printf("mid %d cnt :%d t: %d\n", mid, t.query(mid), cnt);
        if(t.query(mid) >= cnt) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return (ll)hi;
}

int main() {
    cin >> n >> k;
    vector<int> v(n, 0);
    for(auto &it: v) cin >> it;
    fwTree t(65536);
    for(int i = 0; i < k; ++i) {
        t.update(v[i], 1);
    }
    ll sum = 0;
    int next = k;
    k = (k+1)/2;
    sum += Kth(t, k);
    for(int i = 0; i < n-next; ++i) {
        t.update(v[i], -1);
        t.update(v[next+i], 1);
        sum += Kth(t, k);
    }
    cout << sum << "\n";

}