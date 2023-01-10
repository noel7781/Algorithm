#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
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

int solve(vector<pii>& v) {
    int ret = 0;
    DisjointSet s(n);
    for(int i = 0; i < m; ++i) {
        pii tmp = v[i];
        if(s.merge(v[i].first-1, v[i].second-1)) ret++;
        if(ret == n-1) break;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<pii> v(m);
        for(int i = 0; i < m; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        cout << solve(v) << "\n";
    }
}
