#include <iostream>
#include <vector>

using namespace std;
int n, q;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n): parent(n+1), rank(n+1, 1) {
        for(int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(parent[u] == u)
            return u;
        return parent[u]=find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v)
            return;
        if(rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v])
            rank[u]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    DisjointSet uf(n);
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            uf.merge(b, c);
        }
        if(a == 1) {
            if(uf.find(b) == uf.find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
