#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii> > adj;
int depth[100001];
int parent[18][100001];
int largest[18][100001];
int least[18][100001];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    depth[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(pii v: adj[u]) {
            if(depth[v.first] == -1) {
                depth[v.first] = depth[u] + 1;
                parent[0][v.first] = u;
                least[0][v.first] = v.second;
                largest[0][v.first] = v.second;
                q.push(v.first);
            }
        }
    }
}

void lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    int max_dist = -1, min_dist = INT_MAX;
    for(int i = 0; diff; i++) {
        if(diff & 1) {
            max_dist = max(max_dist, largest[i][u]);
            min_dist = min(min_dist, least[i][u]);
            u = parent[i][u];
        }
        diff >>= 1;
    }
    if(u == v) {
        cout << min_dist << " " << max_dist << "\n"; 
        return;
    }
    for(int i = 17; i >= 0; i--) {
        if(parent[i][u] != 0 && parent[i][u] != parent[i][v]) {
            max_dist = max(max_dist, max(largest[i][u], largest[i][v]));
            min_dist = min(min_dist, min(least[i][u], least[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    max_dist = max(max_dist, max(largest[0][u], largest[0][v]));
    min_dist = min(min_dist, min(least[0][u], least[0][v]));
    cout << min_dist << " " << max_dist << "\n"; 
    return;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    memset(depth, -1, sizeof(depth));
    adj.resize(N+1);
    for(int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }
    bfs(1);
    for(int i = 1; i < 18; i++) {
        for(int j = 1; j <= 100000; j++) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            largest[i][j] = max(largest[i-1][j], largest[i-1][parent[i-1][j]]);
            least[i][j] = min(least[i-1][j], least[i-1][parent[i-1][j]]);
        }
    }
    int K; cin >> K;
    while(K--) {
        int a, b; cin >> a >> b;
        lca(a, b);
    }
    return 0;
}