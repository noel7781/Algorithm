#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[1001];
void dfs(int u, vector<int>& is_visit) {
    for(auto next: adj[u]) {
        if(!is_visit[next]) {
            is_visit[next] = 1;
            dfs(next, is_visit);
        }
    }
    return;
}
int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int n1, n2; cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    vector<int> is_visit(N+1, 0);
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(!is_visit[i]) {
            is_visit[i] = 1;
            ans++;
            dfs(i, is_visit);
        }
    }
    cout << ans << "\n";
}