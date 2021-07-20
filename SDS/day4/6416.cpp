#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int a = 0, b = 0;
    map<int, int> m; // for node number
    map<int, int> reverse_graph; // show reversed graph
    map<int, vector<int> > graph; // real graph
    int edge_num = 0;
    int case_num = 1;
    while(true) {
        scanf("%d%d", &a, &b);
        if(a < 0 && b < 0) break;
        if(a != 0 && b != 0) {
            if(m.find(a) == m.end()) {
                m.insert(make_pair(a, edge_num++));
            }
            if(m.find(b) == m.end()) {
                m.insert(make_pair(b, edge_num++));
            }
            graph[m[a]].push_back(m[b]);
            reverse_graph[m[b]] = m[a];
        } else {
            int root_idx = 0;
            // root index 찾기. reverse 그래프 기준 나가는 노드가 없는게 루트
            for(root_idx; root_idx < edge_num; ++root_idx) {
                if(reverse_graph.find(root_idx) == reverse_graph.end())
                    break;
            }
            // q 생성해서 bfs탐색, 이미 발견된 노드가 발견이 또되면 트리가 아님
            bool isTree = true;
            queue<int> q;
            q.push(root_idx);
            vector<bool> visit(edge_num, 0);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                visit[cur] = 1;
                for(int i = 0; i < graph[cur].size(); ++i) {
                    int next = graph[cur][i];
                    if(visit[next]) {
                        isTree = false;
                        break;
                    } else {
                        visit[next] = true;
                        q.push(next);
                    }
                }
            }

            if(isTree) {
                printf("Case %d is a tree.", case_num++);
            } else {
                printf("Case %d is not a tree.", case_num++);
            }
            // 초기화
            reverse_graph.clear();
            graph.clear();
            m.clear();
            edge_num = 0;
        }
    }
}