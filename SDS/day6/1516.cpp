#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > adj;
int cache[502];

int solve(int i) {
    int& ret = cache[i];
    if(ret != -1) return ret;
    if(adj[i].size() == 1) {
        return ret = adj[i][0];
    }
    else {
        int max_cost = 0;
        for(int j = 1; j < adj[i].size(); ++j) {
            max_cost = max(max_cost, solve(adj[i][j]));
        }
        max_cost += adj[i][0];
        return ret = max_cost;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    adj.assign(n+1, vector<int>());
    // adj : cost + 건물번호..
    for(int i = 1; i <= n; ++i) {
        int c; cin >> c; adj[i].push_back(c);
        int b = 0;
        while(true) {
            cin >> b; if(b == -1) break;
            adj[i].push_back(b);
        }
    }

    for(int i = 1; i <= n; ++i) {
        int ret = solve(i);
        cout << ret << "\n";
    }
}