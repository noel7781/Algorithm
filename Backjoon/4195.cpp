#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct DisjointSet {
    vector<int> sum, parent, rank;
    DisjointSet(int n) : sum(n+1), parent(n+1), rank(n+1, 1) {
        for(int i = 1; i <= n; ++i) {
            parent[i] = i;
            sum[i] = 1;
        }
    }
    int find(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v)
            return sum[u];
        sum[v] += sum[u];
        sum[u] = sum[v];
        if(rank[u] > rank[v]) {
            swap(u, v);
        }
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
        return sum[u];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int cnt; cin >> cnt;
        DisjointSet tr(cnt*2);
        map<string, int> friends;
        int start = 1;
        while(cnt--) {
            string name1, name2; cin >> name1 >> name2;
            if(friends[name1] == 0) {
                friends[name1] = start++;
            }
            if(friends[name2] == 0) {
                friends[name2] = start++;
            }
            cout << tr.merge(friends[name1], friends[name2]) << "\n";
        }
    }
}
