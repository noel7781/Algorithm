#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 100001

using namespace std;

int n, m;
int depth[MAX];
int parent[MAX][20];
bool visit[MAX];

vector<vector<int> > g;

void dfs(int v) {
    visit[v] = 1;
    for(int i = 0; i < g[v].size(); ++i) {
        int next = g[v][i];
        if(!visit[next]) {
            depth[next] = depth[v] + 1;
            parent[next][0] = v;
            dfs(next);
        }
    }
    return;
}

int query(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b); // a를 더 깊은 노드로 설정
    int diff = depth[a] - depth[b];
    for(int j = 0; diff; ++j) {
        if(diff % 2) a = parent[a][j];
        diff /= 2;
    }
    if(a != b) {
        for(int j = 19; j >= 0; --j) {
            if(parent[a][j] != 0 && parent[a][j] != parent[b][j]) {
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        a = parent[a][0];
    }
    return a;
}

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(parent, 0, sizeof(parent));
    cin >> n;
    g.assign(n+1, vector<int>());
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[1] = 0;
    dfs(1);
    for(int j = 0; j < 19; j++) {
        for(int i = 1; i <= n; ++i) {
            if(parent[i][j] != 0) {
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        cout << query(a, b) << "\n";
    }
}