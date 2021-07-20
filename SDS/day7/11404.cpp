#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
int n, m;

vector<vector<int> > graph;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;    
    graph.assign(n+1, vector<int>(n+1, 1e9+1));
    for(int i = 1; i <= n; ++i) {
        graph[i][i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int dist = graph[i][j];
            if(dist >= 1e9) {
                cout << 0 << " ";
            } else {
                cout << dist << " ";
            }
        }
        cout << "\n";
    }
}