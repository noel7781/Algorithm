#include <iostream>
#include <vector>

using namespace std;

vector<int> seen, order;

void dfs(int here) {
    seen[here] = 1;
    for(int there = 0; there < adj.size(); ++there) {
        if(adj[here][there] && !seen[there]) {
            dfs(there);
        }
    }
    order.push_back(here);
}

// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니면 빈 벡터를 반환한다.

vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for(int i = 0; i < m; ++i) {
        if(!seen[i]) dfs[i];
    }
    reverse(order.begin(), order.end());
    for(int i = 0; i < m; ++i) {
        for(int j = i+1; j < m; ++j) {
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}