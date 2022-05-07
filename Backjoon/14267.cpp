#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> parent;
vector<int> acc;
vector<int> ans;
int solve(int u) {
    if(u == -1) return 0;
    int& ret = ans[u];
    if(ret != -1) return ret;
    ret = acc[u];
    ret += solve(parent[u]);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    parent.resize(N+1);
    ans.resize(N+1, -1);
    acc.resize(N+1, 0);
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        parent[i] = x;
    }
    for(int i =0; i < M; i++) {
        int e, w; cin >> e >> w;
        acc[e] += w;
    }
    for(int i = 1; i <= N; i++) {
        cout << solve(i) << " ";
    }
    cout << "\n";
    return 0;
}