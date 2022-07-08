#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;
    int r;
};
int N;
vector<Point> V;
struct DS {
    vector<int> rank, parent;
    DS(int n): rank(n, 1), parent(n) {
        for(int i = 0; i < n; i++) {
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

int get_distance(Point& A, Point& B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        V.clear();
        cin >> N;
        DS ds(N+1);
        V.resize(N);
        for(int i = 0; i < N; i++) {
            int x, y, r; cin >> x >> y >> r;
            V[i] = {x, y, r};
        }
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(ds.find(i) == ds.find(j)) continue;
                if(get_distance(V[i], V[j]) <= (V[i].r + V[j].r) * (V[i].r + V[j].r)) {
                    ds.merge(i, j);
                    cnt++;
                }
            }
        }
        cout << N - cnt << "\n";

    }
}