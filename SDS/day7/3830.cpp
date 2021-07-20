#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;

struct disjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> weight;
    vector<vector<int> > childs;
    disjointSet(int n) {
        parent.assign(n+1, 0);
        rank.assign(n+1, 1);
        weight.assign(n+1, 0);
        childs.assign(n+1, vector<int>());
        for(int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        vector<int> child;
        while(u != parent[u]) {
            child.push_back(u);
            u = find(parent[u]);
        }
        childs[u] = child;
        return u;
    }
    void merge(int a, int b, int c) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(rank[a] < rank[b]) {
            swap(a, b);
            c *= -1;
        }
        for(int i = 0; i < childs[b].size(); ++i) {
            weight[childs[b][i]] += c;
        }
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        else {
            disjointSet s(n+1);
            for(int i = 0; i < m; ++i) {
                char c; int x, y, z;
                cin >> c;
                if(c == '!') {
                    cin >> x >> y >> z;                    
                    s.merge(x, y, z);
                } else if(c == '?') {
                    cin >> x >> y;
                    int ret = s.weight[y] - s.weight[x];
                    if(ret >= (int)1e7) {
                        cout << "UNKNOWN\n";
                    } else {
                        cout << ret << "\n";
                    }
                }
            }
        }
    }
}