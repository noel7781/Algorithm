#include <bits/stdc++.h>

using namespace std;

int dist[1001][1001];
int adj[1001][1001];
int count_milks[1001];
int N, Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            adj[i][j] = 5000;
        }
        adj[i][i] = 0;
    }
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int n1, n2; cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    cin >> Q;
    while(Q--) {
        int cmd, r1, r2; cin >> cmd;
        if(cmd == 1) {
            cin >> r1 >> r2;
            int d = adj[r1][r2];
            int add = 1;
            d -= 1;
            while(d >= 0) {
                for(int next = 1; next <= N; next++) {
                    if(adj[next][r2] == d && adj[r1][next] + adj[next][r2] == adj[r1][r2]) {
                        count_milks[next] += add;
                        break;
                    }
                }
                d -= 1;
                add += 1;
            }
        } else {
            cin >> r1;
            cout << count_milks[r1] << "\n";
        }
    }
}
