#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int v[100001];
int ret[100001];

struct disjointSet {
    vector<int> parent;
    vector<int> rank;
    disjointSet(int n) {
        parent.assign(n, 0);
        rank.assign(n, 1);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
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

int main() {
    int t_num; cin >> t_num;
    for(int test_case = 1; test_case <= t_num; ++test_case) {
        memset(v, 0, sizeof(v));
        memset(ret, 0, sizeof(ret));
        cin >> n;
        for(int i = 0; i < n; ++i) {
            v[i] = i; int d; cin >> d;
            v[i] += d;
        }
        struct disjointSet t(n);
        for(int i = 0; i < n; ++i) {
            if(v[i] < n) {
                t.merge(i, v[i]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int parent_idx = t.find(i);
            if(ret[parent_idx] == 0) ans++;
            ret[parent_idx] = 1;
        }
        cout << "Case #" << test_case << "\n";
        cout << ans << "\n";

    }
}
