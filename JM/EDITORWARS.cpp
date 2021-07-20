#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

struct disjointset {
    vector<int> parent, rank, enemy, size;

    disjointset(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int merge(int u, int v) {
        if(u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if(u == v) return u;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
        size[v] += size[u];
        return v;
    }
    
    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }

    bool ack(int u, int v) {
        u = find(u); v = find(v);
        if(enemy[u] == v) return false;
        int a = merge(u, v), b= merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if(b != -1) enemy[b] = a;
        return true;
    }
};

int maxParty(const disjointset& buf) {
    int ret = 0;
    for(int node = 0; node < n; ++node) {
        if(buf.parent[node] == node) {
            int enemy = buf.enemy[node];
            if(enemy > node) continue;
            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            ret += max(mySize, enemySize);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        disjointset s(n);
        bool done = false;
        for(int i = 0; i < m; ++i) {
            string cmd; int a, b;
            cin >> cmd >> a >> b;
            if(cmd == "ACK") {
                if(!s.ack(a,b)) {
                    cout << "CONTRADICTION AT " << i+1 << "\n";
                    done = true;
                    break;
                }
            } else {
                if(!s.dis(a,b)) {
                    cout << "CONTRADICTION AT " << i+1 << "\n";
                    done = true;
                    break;
                }
            }
        }
        if(!done) cout << "MAX PARTY SIZE IS " << maxParty(s) << "\n";
    }
}
