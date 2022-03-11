#include <bits/stdc++.h>
using namespace std;
int N, M;
int dists[101][101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    memset(dists, 0x3f, sizeof(dists));
    for(int i = 1; i <= N; i++) dists[i][i] = 0;
    for(int i = 0; i < M; i++) {
        int n1, n2; cin >> n1 >> n2;
        dists[n1][n2] = 1;
        dists[n2][n1] = 1;
    }
    for(int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
    int ans = -1, min_sum = 1e9;
    for(int i = 1; i <= N; i++) {
        int tmp = 0;
        for(int j = 1; j <= N; j++) tmp += dists[i][j];
        if(tmp < min_sum) {
            min_sum = tmp;
            ans = i;
        }
    }
    cout << ans << "\n";
}