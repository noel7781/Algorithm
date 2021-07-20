#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 1e9

using namespace std;

typedef pair<double, int> pfi;

int n, m;
vector<vector<pfi> > adj;

double solve(int src) {
    double ret = 0;
    vector<double> dist(n, INF);
    dist[src] = 0.0;
    priority_queue<pfi, vector<pfi>, greater<pfi> > pq;
    pq.push(make_pair(0.0, src));
    while(!pq.empty()) {
        double cost = pq.top().first;
        int here = pq.top().second;
        if(here == n-1) return cost;
        pq.pop();
        if(cost > dist[here]) continue;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].second;
            double nextCost = adj[here][i].first + cost;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push(make_pair(nextCost, there));
            }
        }
    }

    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        adj.clear();
        scanf("%d %d", &n, &m);
        adj = vector<vector<pfi> >(n);
        for(int i = 0; i < m; ++i) {
            int a, b; double c; scanf("%d %d %lf", &a, &b, &c);
            adj[a].push_back(make_pair(log(c), b));
            adj[b].push_back(make_pair(log(c), a));
        }
        printf("%.9f\n", exp(solve(0)));
    }
}
