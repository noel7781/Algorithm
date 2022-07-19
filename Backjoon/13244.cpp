#include <bits/stdc++.h>
using namespace std;
int N, M;
bool next_to[1001][1001];
vector<vector<int> > adj;
int dfs(vector<int>& visited, int root) {
    int ret = 1;
    for(const auto& next: adj[root]) {
        if(!visited[next]) {
            visited[next] = 1;
            ret += dfs(visited, next);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        memset(next_to, 0, sizeof(next_to));
        adj.clear();
        cin >> N >> M;
        adj.resize(N+1);
        bool is_tree = true;
        for(int i = 0; i < M; i++) {
            int p, q; cin >> p >> q;
            if(next_to[p][q]) {
                is_tree = false;
            }
            next_to[p][q] = 1;
            next_to[q][p] = 1;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        if(N - M != 1) is_tree = false;
        vector<int> visited(N+1, 0);
        visited[1] = 1;
        int ret = dfs(visited, 1);
        if(ret == N && is_tree) {
            cout << "tree\n";
        } else {
            cout << "graph\n";
        }
    }
}