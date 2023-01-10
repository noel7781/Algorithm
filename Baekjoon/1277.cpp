#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, W;
double M;
vector<pii> V;
double dists[1001];
struct Info {
    double cost;
    int index;
    bool operator<(const Info& o) const {
        return this->cost > o.cost;
    }
};
struct DS {
    vector<int> parent, rank;
    DS(int n): parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return 0 ;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return 1;
    }
};
double get_distance(DS& ds, int i, int j) {
    if(ds.find(i) == ds.find(j)) return 0;
    return sqrt(pow((V[i].first - V[j].first), 2) + pow((V[i].second - V[j].second), 2));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W;
    cin >> M;
    V.resize(N);
    DS ds(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    for(int i = 0; i < W; i++) {
        int p1, p2; cin >> p1 >> p2;
        ds.merge(p1-1, p2-1);
    }
    priority_queue<Info> pq;
    pq.push({0, 0});
    for(int i = 0; i < N; i++) dists[i] = 5e10;
    dists[0] = 0;
    while(!pq.empty()) {
        auto [cost, cur_pos] = pq.top(); pq.pop();
        if(cur_pos == N-1) {
            cout << int(cost * 1000) << "\n";
            return 0;
        }
        if(dists[cur_pos] < cost) continue;
        for(int i = 0; i < N; i++) {
            double distance = get_distance(ds, cur_pos, i);
            if(distance <= M && dists[i] > cost + distance) {
                dists[i] = cost + distance;
                pq.push({cost + distance, i});
            }
        }
    }
}