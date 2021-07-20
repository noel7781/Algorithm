#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;

struct fwTree {
    vector<int> tree;
    fwTree(int n) {
        tree.assign(n+1, 0);
    }
    ll query(int pos) {
        ++pos;
        ll ret = 0;
        while(pos > 0) {
            ret += (ll)tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void update(int pos) {
        pos++;
        while(pos < tree.size()) {
            tree[pos] += 1;
            pos += (pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int> > lines(n+1, vector<int>());
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        lines[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i) {
        sort(lines[i].begin(), lines[i].end());
    }
    struct fwTree t(2004);
    ll ret = 0;
    for(int i = 1; i <= n; ++i) {
        for(auto next: lines[i]) {
            ret += t.query(2002) - t.query(next);
            t.update(next);
        }
    }
    cout << ret << "\n";
}