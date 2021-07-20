#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct segTree {
    int n;
    vector<int> sum;
    segTree(vector<int>& arr) {
        n = arr.size();
        sum.resize(4*n);
        init(arr, 0, n-1, 1);
    }
    int init(vector<int>& arr, int left, int right, int node) {
        if(left == right) return sum[node] = arr[left];
        int mid = (left + right) >> 1;
        return sum[node] = init(arr, left, mid, node*2) + init(arr, mid+1, right, node*2+1);
    }
    int query(int l, int r, int nL, int nR, int n) {
        if(l > nR || r < nL) return 0;
        if(l <= nL && nR <= r) return sum[n];
        int m = (nL + nR) >> 1;
        return query(l, r, nL, m, n*2) + query(l, r, m+1, nR, n*2+1);
    }
    int query(int l, int r) {
        return query(l, r, 0, n-1, 1);
    }
    int update(int i, int v, int nL, int nR, int n) {
        if(i < nL || i > nR) return sum[n];
        if(nL == nR) return sum[n] = v;
        int m = (nL + nR) >> 1;
        return sum[n] = update(i, v, nL, m, n*2) + update(i, v, m+1, nR, n*2+1);
    }
    int update(int i, int v) {
        return update(i, v, 0, n-1, 1);
    }
};

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.in", "r", stdin);
    cin >> n >> m;
    vector<segTree> vs;
    for(int i = 0; i < n; ++i) {
        vector<int> v(n);
        for(auto &it: v) cin >> it;
        vs.push_back(segTree(v));
    }
    for(int i = 0; i < m; ++i) {
        int w, x, y, a1, a2; cin >> w >> x >> y >> a1;
        if(w == 1) {
            cin >> a2;
            int sum = 0;
            for(int i = y-1; i <= a2-1; ++i) {
                sum += vs[i].query(x-1, a1-1);
            }
            cout << sum << "\n";
        } else {
            vs[y-1].update(x-1, a1);
        }
    }
}
