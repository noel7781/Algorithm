#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<vector<int> > adj;

int cache[17][1<<16];

int solve(int now, int cnt, int visited) {
    if(cnt == n-1) {
        if(adj[now][0] > 0) 
            return adj[now][0];
        else
            return 1e9;
    }
    int& ret = cache[now][visited];
    if(ret != -1)
        return ret;
    ret = 1e9;
    for(int i = 1; i < n; ++i) {
        if(visited & (1 << i))
            continue;
        int cost = adj[now][i];
        if(cost == 0)
            continue;
        ret = min(ret,  cost + solve(i, cnt+1, visited | (1 << i)));
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    adj.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    int visited = 0;
    cout << solve(0, 0, visited) << "\n";
}
