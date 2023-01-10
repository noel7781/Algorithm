#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int V, E;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n): parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return (parent[u] = find(parent[u]));
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

int solve(vector<pair<int, pii> >& edges) {
    int ret = 0;
    int cnt = 0;
    DisjointSet s(V);
    for(int i = 0; i < E; ++i) {
        int cost = edges[i].first, v1 = edges[i].second.first-1, v2 = edges[i].second.second-1;
        if(s.merge(v1, v2)) {
            ret += cost;
            cnt += 1;
        }
        if(cnt == V-1) break;
    }
    return ret;
}

int main() {
    cin >> V >> E;
    vector<pair<int, pii> > edges;
    for(int i = 0; i < E; ++i) {
        int a, b, cost; cin >> a >> b >> cost;
        edges.push_back(make_pair(cost, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    cout << solve(edges) << "\n";
}
