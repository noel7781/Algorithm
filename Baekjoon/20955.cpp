#include <bits/stdc++.h>
using namespace std;
int N, M;
struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n): parent(n+1), rank(n+1, 1) {
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return 0;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return 1;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int ret = 0;
    int u, v;
    DisjointSet ds(N);
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        if(!ds.merge(u, v)) {
            ret++;
        }
    }
    for(int i = 2; i <= N; i++) {
        if(ds.merge(1, i)) ret++;
    }
    cout << ret << "\n";
}