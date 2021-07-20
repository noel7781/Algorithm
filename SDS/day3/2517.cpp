#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>


#define MAX_NUM 500001

using namespace std;

int n;
vector<int> v;

struct segTree {
    int n;
    vector<int> sumArr;
    segTree(int number) {
        n = number;
        sumArr.assign(4*n, 0);
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return sumArr[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, nodeLeft, mid, node*2) +
               query(left, right, mid+1, nodeRight, node*2+1);
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    int update(int index, int newValue, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || nodeRight < index) return sumArr[node];
        if(nodeLeft == nodeRight) return sumArr[node] += 1;
        int mid = (nodeLeft + nodeRight) / 2;
        return sumArr[node] = update(index, newValue, nodeLeft, mid, node*2) +
                              update(index, newValue, mid+1, nodeRight, node*2+1);
    }
    int update(int index, int newValue) {
        return update(index, newValue, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.assign(n, 0);
    set<int> s;
    map<int, int> m;
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        int k; cin >> k;
        s.insert(k);
        v[i] = k;
    }
    for(auto it = s.begin(); it != s.end(); ++it) {
        m.insert(make_pair(*it, idx++));
    }
    for(int i = 0; i < n; ++i) {
        v[i] = m[v[i]];
    }
    struct segTree t(500001);
    for(int i = 0; i < n; ++i) {
        int ret = t.query(0,500000) - t.query(0,v[i]);
        cout << ret+1 << " ";
        t.update(v[i], 1);

    }
}