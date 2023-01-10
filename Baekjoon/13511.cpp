#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;

vector<vector<pii> > adj;
int depth[100001];
int parent[18][100001];
ll dists[100001];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    depth[src] = 0;
    dists[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (depth[v.first] == -1) {
                depth[v.first] = depth[u] + 1;
                parent[0][v.first] = u;
                dists[v.first] = dists[u] + v.second;
                q.push(v.first);
            }
        }
    }
}

int get_lca(int u, int v) {
    ll du = depth[u], dv = depth[v];
    if(du < dv) swap(u, v);
    ll diff = depth[u] - depth[v];
    for(int i = 0; diff; i++) {
        if(diff & 1) {
            u = parent[i][u];
        }
        diff >>= 1;
    }
    if(u == v) {
        return u;
    } else {
        for(int i = 17; i >= 0; i--) {
            if(parent[i][u] != 0 && parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
}

void get_kth(int u, int v, ll k) {
    int lca = get_lca(u, v);
    ll du = depth[u], dv = depth[v];
    ll dlca = depth[lca];
    k -= 1;
    if(du - dlca == k) {
        cout << lca << "\n";
        return;
    }
    if(du - dlca > k) {
        // 왼쪽
        ll diff = k;
        // printf("[1]diff %d\n", diff);
        for(int i = 0; diff; i++) {
            if(diff & 1) {
                u = parent[i][u];
            }
            diff >>= 1;
        }
        cout << u << "\n";
    } else {
        ll tmp = du + dv - 2*dlca;
        ll diff = tmp - k;
        // printf("[2]diff %d\n", diff);
        for(int i = 0; diff; i++) {
            if(diff & 1) {
                v = parent[i][v];
            }
            diff >>= 1;
        }
        cout << v << "\n";
        // 오른쪽
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    adj.resize(N+1);
    for(int i = 0; i < N-1; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    dists[1] = 0;
    bfs(1);
    for(int i = 1; i < 18; i++) {
        for(int j = 1; j <= 100000; j++) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    int M; cin >> M;
    while(M--) {
        int cmd, u, v; ll k; cin >> cmd;
        if(cmd == 1) {
            cin >> u >> v;
            int lca = get_lca(u, v);
            cout << dists[u] + dists[v] - 2 * dists[lca] << "\n";
        } else {
            cin >> u >> v >> k;
            get_kth(u, v, k);
        }
    }
}