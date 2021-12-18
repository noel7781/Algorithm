#include <iostream>
#include <vector>

using namespace std;

vector<int> seen, order;

void dfs(int here) {
    seen[here] = 1;
    for(int there = 0; there < adj.size(); ++there) {
        if(adj[here][there] && !seen[there])
            dfs(there);
    }
    order.push_back(there);
}

vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for(int i = 0; i < m; ++i) if(!seen[i]) dfs(i);
    for(int i = 0; i < m; ++i) {
        for(int j = i+1; j < m; ++j) {
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}
