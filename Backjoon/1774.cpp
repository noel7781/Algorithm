#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i) {
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

int n;

double getDistance(tiii A, tiii B) {
    int dx = get<0>(A) - get<0>(B);
    int dy = get<1>(A) - get<1>(B); 
    int dz = get<2>(A) - get<2>(B);
    return min(abs(dx), min(abs(dy), abs(dz)));
}

int main() {
    scanf("%d", &n);
    vector<tiii> v(n);
    DisjointSet s(n);
    for(int i = 0; i < n; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c); tiii tmp = make_tuple(a, b, c);
        v[i] = tmp;
    }
    vector<pair<int, pii> > edges;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) edges.push_back(make_pair(getDistance(v[i], v[j]), make_pair(i, j)));
        }
    }
    sort(edges.begin(), edges.end());
    int ret = 0;
    for(int i = 0; i < edges.size(); ++i) {
        if(s.merge(edges[i].second.first, edges[i].second.second)) {
            ret += edges[i].first;
        }
    }
    printf("%d\n", ret);
}
