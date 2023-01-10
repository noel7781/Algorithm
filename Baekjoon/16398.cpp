#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Info {
    int p1;
    int p2;
    int cost;
    bool operator<(const Info& rhs) const {
        return cost < rhs.cost;
    }
};
int N;
struct DS {
    vector<int> parent, rank;
    DS(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) parent[i] = i;
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
        if(rank[u] == rank[v]) rank[v]++;
    }
};
vector<Info> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    DS ds(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int c; cin >> c;
            V.push_back({i, j, c});
        }
    }
    sort(V.begin(), V.end());
    ll ans = 0;
    int cnt = 0;
    for(auto [p1, p2, cost]: V) {
        if(ds.find(p1) == ds.find(p2)) {
            continue;
        } else {
            cnt++;
            ds.merge(p1, p2);
            ans += cost;
            if(cnt == N) break;
        }
    }
    cout << ans << "\n";
}