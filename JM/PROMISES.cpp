#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, M, N;
vector<vector<int> > road;
int W[201][201];

void floyd() {
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if(i == j) W[i][j] = 0;
            else W[i][j] = road[i][j];
        }
    }
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
}

bool update(int a, int b, int c) {
    if(adj[a][b] <= c) return false;
    for(int x = 0; x < V; ++x)
        for(int y = 0; y < V; +y)
            adj[x][y] = min(adj[x][y], min(adj[x][a] + c + adj[b][y], adj[x][b] + c + adj[a][y]));
}

int main() {
    int t; cin >> t;
    while(t--) {
        road.clear();
        cin >> V >> M >> N;
        for(int i = 0; i < 201; ++i) {
            for(int j = 0; j < 201; ++j) {
                W[i][j] = 1e9;
            }
        }
        road = vector<vector<int> >(V, vector<int>(V, 1e9));
        for(int i = 0; i < M; ++i) {
            int a, b, c; cin >> a >> b >> c;
            road[a][b] = c; road[b][a] = c;
        }
        floyd();
        int count = 0;
        for(int i = 0; i < N; ++i) {
            int a, b, c; cin >> a >> b >> c;
            if(W[a][b] <= c) count += 1;
            else {
                road[a][b] = c;
                floyd();
            }
        }
        cout << count << "\n";
    }
}
