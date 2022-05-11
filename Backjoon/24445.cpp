#include <bits/stdc++.h>
using namespace std;
int N, M, R;
vector<vector<int> > adj;
vector<int> visit_order;
int order = 1;
void bfs(int u) {
    queue<int> q;
    q.push(u);
    visit_order[u] = 1;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(const auto& next: adj[now]) {
            if(visit_order[next] == 0) {
                visit_order[next] = ++order;
                q.push(next);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    adj.resize(N+1);
    visit_order.resize(N+1);
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }
    bfs(R);
    for(int i = 1; i <= N; i++) {
        cout << visit_order[i] << "\n";
    }
    return 0;
}