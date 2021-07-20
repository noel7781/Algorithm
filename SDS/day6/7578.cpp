#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 500002

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mapping[1000002];

struct segTree {
    int n;
    vector<ll> cnt;
    segTree() {
        n = MAX;
        cnt.resize(4*MAX);
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

    ll update(int i, int nL, int nR, int n) {
        if(i < nL || i > nR) return cnt[n];
        if(nL == nR) return ++cnt[n];
        int m = (nL + nR) >> 1;
        return cnt[n] = update(i, nL, m, n*2) + update(i, m+1, nR, n*2+1);
    }
    ll update(int i) {
        return update(i, 0, n-1, 1);
    }
};

bool comp(pii a, pii b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    segTree t;
    int n; cin >> n;
    // vector<pii> vp;
    for(int i = 1; i <= n; ++i) {
        int num; cin >> num;
        // vp.push_back(pii(i, num));
        mapping[num] = i;
    }
    ll ret = 0;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        int idx = mapping[num];
        ret += (ll)t.query(idx+1, MAX-1);
        t.update(idx);
    }
    cout << ret << "\n";
}