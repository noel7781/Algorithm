#include <bits/stdc++.h>
using namespace std;
int N;
int T, C;
int dists[10001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int prev;
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        cin >> T >> C;
        dists[i] = T;
        for(int j = 0; j < C; j++) {
            cin >> prev;
            dists[i] = max(dists[i], dists[prev] + T);
        }
        ret = max(ret, dists[i]);
    }
    cout << ret << "\n";
}