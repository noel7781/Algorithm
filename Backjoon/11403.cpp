#include <bits/stdc++.h>
using namespace std;
int N;
int dist[101][101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int x; cin >> x;
            if(i == j) continue;
            else {
                if(x == 1) dist[i][j] = 1;
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dist[i][j] >= 1000) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }
}