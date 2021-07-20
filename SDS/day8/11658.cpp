#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct segTree {
    int n;
    vector<int> tree;
    segTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(n+1, 0);
        for(int i = 0; i < n; ++i) {
            add(i, arr[i]);
        }
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
    void add(int pos, int v) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += v;
            pos += (pos & -pos);
        }
    }
};

int rangeSum(vector<segTree>& t, int h, int l, int r) {
    segTree ft = t[h-1];
    return ft.query(r) - ft.query(l-1);
}

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<segTree> vs;
    vector<vector<int> > vecs;
    for(int i = 0; i < n; ++i) {
        vector<int> v(n);
        for(auto &it: v) cin >> it;
        vs.push_back(segTree(v));
        vecs.push_back(v);
    }
    for(int i = 0; i < m; ++i) {
        int w, x, y, a1, a2; cin >> w >> x >> y >> a1;
        if(w == 1) {
            cin >> a2;
            int sum = 0;
            for(int i = y; i <= a2; ++i) {
                sum += rangeSum(vs, i, x-1, a1-1);
            }
            cout << sum << "\n";
        } else {
            int diff = a1 - vecs[y-1][x-1];
            // printf("diff %d\n", diff);
            vs[y-1].add(x-1, diff);
        }
    }
}