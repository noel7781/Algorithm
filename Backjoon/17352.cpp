#include <bits/stdc++.h>
using namespace std;
int N;
struct UF {
    vector<int> parent, rank;
    UF(int n) : parent(n+1), rank(n+1, 1) {
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
    cin >> N;
    UF uf(N);
    for(int i = 0; i < N-2; i++) {
        int x, y; cin >> x >> y;
        uf.merge(x, y);
    }
    int p1 = uf.find(1);
    for(int i = 2; i <= N; i++) {
        if(p1 != uf.find(i)) {
            cout << p1 << " " << uf.find(i) << "\n";
            return 0;
        }
    }
    return 0;
}