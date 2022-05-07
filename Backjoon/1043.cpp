#include <bits/stdc++.h>
using namespace std;
int N, M;
struct ds {
    vector<int> parent, rank;
    ds(int n): parent(n+1), rank(n+1, 1) {
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ds t(N);
    int ret = 0;
    vector<int> cand;
    for(int i = 0; i < M+1; i++) {
        int cnts; cin >> cnts;
        if(i == 0) {
            for(int j = 0; j < cnts; j++) {
                int x; cin >> x;
                t.merge(0, x);    
            }
        } else {
            vector<int> v(cnts);
            for(int j = 0; j < cnts; j++) {
                cin >> v[j];
            }
            for(int j = 1; j < cnts; j++) {
                t.merge(v[0], v[j]);
            }
            cand.push_back(v[0]);
        }
    }
    for(auto num: cand) {
        if(t.find(0) == t.find(num)) continue;
        ret++;
    }
    cout << ret << "\n";
}