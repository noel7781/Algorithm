#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, w;
int waits[1001];
int in_degree[1001];
vector<vector<int> > g;

int solve() {
    int ret = 0;
    int ans[1001];
    memset(ans, 0, sizeof(ans));
    queue<int> q;
    vector<int> order;
    for(int i = 1; i <= n; ++i) {
        if(in_degree[i] == 0) { 
            q.push(i);
            ans[i] = waits[i];
        }
    }

    while(!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for(int n: g[v]) {
            ans[n] = max(ans[n], ans[v] + waits[n]);
            if(!--in_degree[n]) {
                q.push(n);
            }
        }
    }
    ret = ans[w];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        g.clear();
        memset(waits, 0, sizeof(waits));
        memset(in_degree, 0, sizeof(in_degree));
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            cin >> waits[i];
        }
        g.assign(n+1, vector<int>());
        for(int i = 0; i < k; ++i) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            in_degree[b]++;
        }
        cin >> w;
        int ret = solve();
        cout << ret << "\n";
    }
}
