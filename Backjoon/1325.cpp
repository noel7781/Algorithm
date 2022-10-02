#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<int> > adj;
int is_visit[10001];
vector<pii> V;
int dfs(int k) {
    int ret = 1;
    bool is_leaf = true;
    for(const auto& next: adj[k]) {
        if(!is_visit[next]) is_leaf = false;
    }
    if(is_leaf) return 1;
    for(const auto& next: adj[k]) {
        if(!is_visit[next]) {
            is_visit[next] = 1;
            ret += dfs(next);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int p, q; cin >> p >> q;
        adj[q].push_back(p);
    }
    for(int i = 1; i <= N; i++) {
        memset(is_visit, 0, sizeof(is_visit));
        is_visit[i] = 1;
        int cnt = dfs(i);
        V.push_back({-cnt, i});
    }
    sort(V.begin(), V.end());
    int ans = V[0].first;
    for(const auto& it: V) {
        if(it.first == ans) cout << it.second << " ";
    }
    cout << "\n";
    return 0;
}