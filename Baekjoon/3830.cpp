#include <iostream>
#include <vector>

using namespace std;

int n, m;

struct disjointSet {
    vector<int> parent;
    vector<int> dist;
    disjointSet(int n) {
        parent.assign(n, 0);
        dist.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u == parent[u]) return u;
        int p = parent[u];
        parent[u] = find(p);
        dist[u] += dist[p];
        return parent[u];
    }

    void merge(int u, int v, int w) {
        int p_u = find(u); int p_v = find(v);
        if(p_u == p_v) return;
        dist[p_v] = dist[u] - dist[v] + w;
        parent[p_v] = p_u;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        struct disjointSet ds(n+1);
        for(int i = 0; i < m; ++i) {
            char c; int a, b; cin >> c >> a >> b;
            if(c == '!') {
                int w; cin >> w;
                ds.merge(a, b, w);
            } else {
                if(ds.find(a) != ds.find(b)) {
                    cout << "UNKNOWN\n";
                } else {
                    cout << ds.dist[b] - ds.dist[a] << "\n";
                }
            }
        }
    }
}
