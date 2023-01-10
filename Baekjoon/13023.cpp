#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > adj;
int visited[2001];
int is_done = 0;
void dfs(int root, int h) {
    if(h == 4) {
        is_done = 1;
        return;
    }
    for(const auto& next: adj[root]) {
        if(is_done) return;
        if(!visited[next]) {
            visited[next] = 1;
            dfs(next, h+1);
            visited[next] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N);
    for(int i = 0; i < M; i++) {
        int p1, p2; cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    for(int i = 0; i < N; i++) {
        if(is_done) break;
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        dfs(i, 0);
    }
    cout << is_done << "\n";
    return 0;
}