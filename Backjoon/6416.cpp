#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int main() {
    int case_num = 0;
    int s, e;
    int edge_num = 0;
    map<int, int> m;
    map<int, int> back_graph;
    map<int, vector<int> > graph;
    while(true) {
        scanf("%d%d", &s, &e);
        if(s == 0 && e == 0) {
            bool isTree = true;
            int root_idx = 0;
            vector<bool> visit(edge_num, 0);
            for(int i = 0; i < edge_num; ++i) {
                if(back_graph.find(i) == back_graph.end()) {
                    root_idx = i;
                    break;
                }
            }
            visit[root_idx] = 1;
            int visit_cnt = 1;
            queue<int> q;
            q.push(root_idx);
            while(!q.empty()) {
                int top = q.front(); q.pop();
                for(int i = 0; i < graph[top].size(); ++i) {
                    int next = graph[top][i];
                    if(!visit[next]) {
                        visit[next] = 1;
                        q.push(next);
                        visit_cnt += 1;
                    } else {
                        isTree = false;
                        break;
                    }
                }
            }
            if(visit_cnt == edge_num) isTree = true;
            else isTree = false;
            case_num += 1;
            if(back_graph.size() != edge_num -1) isTree = false;
            if(isTree) {
                printf("Case %d is a tree.\n", case_num);
            } else {
                printf("Case %d is not a tree.\n", case_num);
            }
            edge_num = 0;
            m.clear();
            back_graph.clear();
            graph.clear();
        } else if(s < 0 && e < 0) {
            return 0;
        } else {
            auto it = m.find(s);
            if(it == m.end()) {
                m.insert(make_pair(s, edge_num++));
            }
            it = m.find(e);
            if(it == m.end()) {
                m.insert(make_pair(e, edge_num++));
            }
            back_graph[m[e]] = m[s];
            graph[m[s]].push_back(m[e]);
        }
    }
}
