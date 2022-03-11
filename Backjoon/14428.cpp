#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int N, M;

struct segTree {
    int n;
    vector<int> rmi;
    segTree() {
        n = N;
        rmi.resize(4*n);
        init(0, n-1, 1);
    }
    int init(int left, int right, int node) {
        if(left == right) {
            return rmi[node] = left;
        }
        int mid = left+right>>1;
        int lidx = init(left, mid, node*2); int ridx = init(mid+1, right, node*2+1);
        int ret = lidx;
        if(v[lidx] > v[ridx]) ret = ridx;
        return rmi[node] = ret;
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(nodeLeft > right || nodeRight < left) return 1e9;
        if(left <= nodeLeft && nodeRight <= right) return rmi[node];
        int mid = nodeLeft+nodeRight>>1;
        int lidx = query(left, right, nodeLeft, mid, node*2);
        int ridx = query(left, right, mid+1, nodeRight, node*2+1);
        int ret = lidx;
        if(ridx >= 1e9) return ret;
        if(lidx >= 1e9 || v[lidx] > v[ridx]) ret = ridx;
        return ret;
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    int update(int index, int newValue, int nodeLeft, int nodeRight, int node) {
        if(nodeLeft == nodeRight) return rmi[node];
        if(nodeLeft > index || index > nodeRight) return rmi[node];
        int mid = nodeLeft+nodeRight>>1;
        int lidx = update(index, newValue, nodeLeft, mid, node*2);
        int ridx = update(index, newValue, mid+1, nodeRight, node*2+1);
        int ret = lidx;
        if(v[lidx] > v[ridx]) ret = ridx;
        return rmi[node] = ret;
    }
    int update(int index, int newValue) {
        v[index] = newValue;
        return update(index, newValue, 0, n-1, 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; v.resize(N); for(auto &it: v) cin >> it;
    segTree t;
    cin >> M;
    while(M--) {
        int c, i, j; cin >> c >> i >> j;
        if(c == 1) {
            t.update(i-1, j);
        } else {
            cout << t.query(i-1, j-1)+1 << "\n";
        }
    }
}