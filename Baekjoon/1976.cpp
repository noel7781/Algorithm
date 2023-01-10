#include <iostream>
#include <vector>

using namespace std;

int adj[202][202];

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v)
            return;
        if(rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int size; cin >> size;
    int visits; cin >> visits;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            cin >> adj[i][j];
        }
    }
    DisjointSet t(size);
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(adj[i][j])
                t.merge(i, j);
        }
    }
    bool is_ok = true;
    int n, parent = -1;
    for(int i = 0; i < visits; ++i) {
        cin >> n;
        if(parent == -1) {
            parent = t.find(n-1);
        } else {
            if(parent != t.find(n-1)) {
                is_ok = false;
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
