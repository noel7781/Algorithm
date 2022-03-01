#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> my;
struct DS {
    vector<int> p, r;
    DS(int n) : p(n+1), r(n+1, 1) {
        for(int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }
    int find(int u) {
        if(u==p[u]) return u;
        return p[u] = find(p[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return 0;
        if(r[u] > r[v]) swap(u, v);
        p[u] = v;
        if(r[u] == r[v]) r[v]++;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    vector<my> v(M);
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {c, a, b};
    }
    DS ds(N);
    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < M; i++) {
        auto [c, a, b] = v[i];
        if(ds.merge(a, b)) {
            ans += c;
            cnt++;
            if(cnt == N-2) break;
        }
    }
    cout << ans << "\n";
}