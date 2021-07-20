#include <iostream>
#include <vector>

using namespace std;

int n;

void solve(vector<vector<int> > adj) {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) adj[i][j] = 0;
                else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(adj[i][j] == int(1e9)) adj[i][j] = 0;
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<vector<int> > adj(n, vector<int>(n, 1e9));
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a-1][b-1] = min(adj[a-1][b-1], c);
    }
    solve(adj);
}
