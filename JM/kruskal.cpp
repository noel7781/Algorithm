#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet;
const int MAX_V = 100;

// 정점의 갯수
int V;
// 그래프의 인접 리스트 (연결된 정점번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];

int kruskal(vector<pair<int, int> >& selected) {
    int ret = 0;
    selected.clear();
    vector<pair<int, pair<int, int> > > edges;
    for(int u = 0; u < V; ++u) {
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, cost = adj[u][u].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet sets(V);
    for(int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}