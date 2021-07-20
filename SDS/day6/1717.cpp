#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) {
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
};

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    DisjointSet s(n+1);
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) {
            s.merge(b, c);
        } else {
            if(s.find(b) == s.find(c)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}