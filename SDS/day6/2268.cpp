#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1000001

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
struct segTree {
    int n;
    vector<ll> cnt;
    segTree(int k) {
        n = k;
        cnt.resize(4*n);
    }

    ll query(int left, int right, int nL, int nR, int n) {
        if(left > nR || right < nL) return 0;
        if(left <= nL && nR <= right) return cnt[n];
        int m = (nL + nR) >> 1;
        return query(left, right, nL, m, n*2) + query(left, right, m+1, nR, n*2+1);
    }
    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }

    ll update(int i, int v, int nL, int nR, int n) {
        if(i < nL || i > nR) return cnt[n];
        if(nL == nR) return cnt[n] = (ll)v;
        int m = (nL + nR) >> 1;
        return cnt[n] = update(i, v, nL, m, n*2) + update(i, v, m+1, nR, n*2+1);
    }
    ll update(int i, int v) {
        return update(i, v, 0, n-1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    segTree t(n+1);
    ll ret = 0;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) {
            if(b > c) swap(b, c);
            cout << t.query(b, c) << "\n";
        } else {
            t.update(b, c);
        }
    }
}