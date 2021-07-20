#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> visit;

void dfs(vector<int>& ret, int s) {
    visit[s] = 1;
    for(int i = 0; i < adj[s].size(); ++i) {
        int next = adj[s][i];
        if(!visit[next]) {
            dfs(ret, next);
        }
    }
    ret.push_back(s);
}

int main() {
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    visit.assign(n+1, 0);
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> ret;
    for(int s = 1; s <= n; ++s) {
        if(!visit[s])
            dfs(ret, s);
    }
    reverse(ret.begin(), ret.end());
    for(auto it: ret) cout << it << " ";
}