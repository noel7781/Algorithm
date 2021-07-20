#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

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

double getDistance(pdd A, pdd B) {
    double dx = A.first - B.first;
    double dy = A.second - B.second;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    scanf("%d", &n);
    vector<pdd> v(n);
    DisjointSet s(n);
    for(int i = 0; i < n; ++i) {
        scanf("%lf %lf", &v[i].first, &v[i].second);
    }
    vector<pair<double, pdd> > edges;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) edges.push_back(make_pair(getDistance(v[i], v[j]), make_pair(i, j)));
        }
    }
    sort(edges.begin(), edges.end());
    double ret = 0;
    int cnt = 0;
    for(int i = 0; i < edges.size(); ++i) {
        if(s.merge(edges[i].second.first, edges[i].second.second)) {
            ret += edges[i].first;
            cnt += 1;
        }
        if(cnt == n-1) break;
    }
    printf("%.4f\n", ret);
}
