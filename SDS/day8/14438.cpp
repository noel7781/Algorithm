#include <iostream>
#include <vector>

#define PIVOT (1<<17)

using namespace std;

int tree[PIVOT*2];

void update(int idx, int val) {
    idx += PIVOT;
    tree[idx] = val;
    idx /= 2;
    while(idx > 0) {
        tree[idx] = min(tree[idx*2], tree[idx*2+1]);
        idx /= 2;
    }
}

int query(int l, int r) {
    l += PIVOT; r += PIVOT;
    int ret = 1e9+5;
    while(l <= r) {
        if(l % 2 == 1) ret = min(ret, tree[l++]);
        if(r % 2 == 0) ret = min(ret, tree[r--]);
        l /= 2; r /= 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("test.in", "r", stdin);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int val; cin >> val;
        update(i, val);
    }
    int m; cin >> m;
    while(m--) {
        int c, l, r; cin >> c >> l >> r;
        if(c == 2)
            cout << query(l, r) << "\n";
        else
            update(l, r);
    }
}