#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
bool isConflictParentIdx[100001];

struct disjointSet {
    vector<int> parent;
    vector<int> dist;
    // vector<int> rank;
    disjointSet(int n) {
        parent.assign(n, 0);
        dist.assign(n, 0);
        // rank.assign(n, 1);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(parent[u] == u) return u;
        int p = parent[u];
        if(isConflictParentIdx[u]) isConflictParentIdx[p] = 1;
        parent[u] = find(p);
        if(isConflictParentIdx[p]) isConflictParentIdx[parent[u]] = 1;
        dist[u] += dist[p];
        return parent[u];
    }
    void merge(int u, int v, int w) {
        int p_u = find(u), p_v = find(v);
        if(p_u == p_v) return;
        // if(rank[p_u] < rank[p_v]) swap(p_u, p_v);
        dist[p_v] = dist[u] + w - dist[v];
        parent[p_v] = p_u;
        if(isConflictParentIdx[p_v] || isConflictParentIdx[v] || isConflictParentIdx[u]) isConflictParentIdx[p_u] = 1;
        // if(rank[p_u] == rank[p_v]) rank[p_u]++;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t_num; cin >> t_num;
    for(int test_case = 1; test_case <= t_num; ++test_case) {
        cout << "Case #" << test_case << "\n";
        cin >> n >> k;
        struct disjointSet ds(n+1);
        memset(isConflictParentIdx, 0, sizeof(isConflictParentIdx));
        for(int i = 0; i < k; ++i) {
            int c, n1, n2, w;
            cin >> c >> n1 >> n2;
            if(c == 1) {
                cin >> w;
                if(n1 != n2) {
                    if(ds.find(n1) != ds.find(n2)) {
                        // ds.dist[n1] = ds.dist[n2] + w
                        ds.merge(n1, n2, -w);
                    } else {
                        if(ds.dist[n1] - ds.dist[n2] != w) {
                            // Conflict state
                            int n1_parent = ds.find(n1);
                            int n2_parent = ds.find(n2);
                            isConflictParentIdx[n1_parent] = 1;
                            isConflictParentIdx[n2_parent] = 1;
                        }
                    }
                } else {
                    if(w != 0) {
                        isConflictParentIdx[ds.find(n1)] = 1;
                    }
                }
            } else {
                if(n1 != n2) {
                    if(ds.find(n1) != ds.find(n2)) {
                        cout << "NC\n";
                    } else {
                        if(isConflictParentIdx[ds.find(n1)]) {
                            cout << "CF\n";
                        } else {
                            cout << ds.dist[n1] - ds.dist[n2] << "\n";
                        }
                    }
                } else {
                    if(isConflictParentIdx[ds.find(n1)]) {
                        cout << "CF\n";
                    } else {
                        cout << 0 << "\n";
                    }
                }
            }
        }
    }
}