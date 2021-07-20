#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int V, E;
int adj[502][502];
int W[502][502];

void floyd(vector<int>& regulations) {
    vector<pair<int, int> > order;
    for(int i = 0; i < V; ++i) {
        order.push_back(make_pair(regulations[i], i));
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if(i == j) W[i][j] = 0;
            else W[i][j] = adj[i][j];
        }
    }
    for(int k = 0; k < V; ++k) {
        int w = order[k].second;
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(adj[i][w] + regulations[w] + adj[w][j], W[i][j]);
            }
        }
    }
}

int main() {
    cin >> V >> E;
    vector<int> regulations(V);
    for(auto &x: regulations) {
        cin >> x;
    }
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            adj[i][j] = 1e9;
        }
    }
    for(int i = 0; i < E; ++i) {
        int a, b, c; cin >> a >> b >> c;
        a -= 1; b -= 1;
        adj[a][b] = c; adj[b][a] = c;
    }
    floyd(regulations);
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        int s, t; cin >> s >> t;
        s -= 1; t -= 1;
        cout << W[s][t] << "\n";
    }
}
