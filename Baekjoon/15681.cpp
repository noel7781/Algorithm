#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, r, q;
vector<vector<int> > g;
bool visit[100001];
int cache[100001];

int dfs(int root) {
    int& ret = cache[root];
    if(ret != -1) return ret;
    ret = 1;
    bool isLeaf = true;
    for(int next: g[root]) {
        if(!visit[next]) {
            visit[next] = true;
            ret += dfs(next);
            isLeaf = false;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> r >> q;
    g.assign(n+1, vector<int>());
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visit[r] = true;
    dfs(r);
    for(int i = 0; i < q; ++i) {
        int r; cin >> r;
        cout << dfs(r) << "\n";
    }
}
