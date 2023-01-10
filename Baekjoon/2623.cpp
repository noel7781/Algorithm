#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > adj;
int ins[1001];
vector<int> solve() {
    vector<int> ans;
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(ins[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int i = 0; i < adj[cur].size(); i++) {
            ins[adj[cur][i]]--;
            if(ins[adj[cur][i]] == 0) {
                q.push(adj[cur][i]);
            }
        }
    }
    if(ans.size() < N) {
        return vector<int>();
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        int P; cin >> P;
        int prev = -1;
        for(int i = 0; i < P; i++) {
            int x; cin >> x;
            if(i == 0) {
                prev = x;
            } else {
                ins[x]++;
                adj[prev].push_back(x);
                prev = x;
            }
        }
    }
    vector<int> ret = solve();
    if(ret.size() == 0) {
        cout << 0 << "\n";
    } else {
        for(auto it: ret) cout << it << " ";
        cout << "\n";
    }
}