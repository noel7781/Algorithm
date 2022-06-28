#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, K;
vector<pii> V;
struct DS {
    vector<int> parent, rank;
    DS(int n) : parent(n+1), rank(n+1, 1) {
        for(int i = 0; i <= n; i++) {
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    DS ds(N+1);
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        V.push_back({x, i});
    }
    sort(V.begin(), V.end());
    int merge_count = 0;
    for(int i = 0; i < M; i++) {
        int p, q; cin >> p >> q;
        if(ds.merge(p, q)) {
            merge_count++;
        }
    }
    int need_pay = 0;
    for(int i = 0; i < N; i++) {
        if(ds.merge(0, V[i].second)) {
            need_pay += V[i].first;
        }
    }
    if(need_pay <= K) {
        cout << need_pay << "\n";
    } else {
        cout << "Oh no\n";
    }
    return 0;
}