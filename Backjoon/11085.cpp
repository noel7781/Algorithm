#include <bits/stdc++.h>
using namespace std;
int P, W;
int C, D;
struct Info {
    int cost;
    int p;
    int q;
    bool operator<(const Info& rhs) const {
        return cost > rhs.cost;
    }
};
struct DS {
    vector<int> p, rank;
    DS(int n) : p(n), rank(n, 1) {
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int u) {
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        p[u] = v;
        if(rank[u] == rank[v]) {
            rank[v]++;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> P >> W;
    cin >> C >> D;
    vector<Info> V(W);
    for(int i = 0; i < W; i++) {
        cin >> V[i].p >> V[i].q >> V[i].cost;
    }
    sort(V.begin(), V.end());
    DS ds(P);
    int ans = 1e9;
    for(int i = 0; i < W; i++) {
        if(ds.find(C) == ds.find(D)) break;
        ans = min(ans, V[i].cost);
        ds.merge(V[i].p, V[i].q);
    }
    cout << ans;
    
}