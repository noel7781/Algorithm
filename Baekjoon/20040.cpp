#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

struct Union {
    int n;
    vector<int> parent;
    vector<int> rank;

    Union(int n) {
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(&u, &v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v] += 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    Union set(n);
    int ret = 0;
    for(int i = 0; i < m; ++i) {
        int v1, v2; cin >> v1 >> v2;
        if(set.find(v1) == set.find(v2)) {
            ret = i+1;
            break;
        } else {
            set.merge(v1, v2);
        }
    }
    cout << ret << "\n";
    return 0;
}
