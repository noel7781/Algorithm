#include <bits/stdc++.h>
using namespace std;
int N;
int cows[11];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cows, -1, sizeof(cows));
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int n, p; cin >> n >> p;
        if(cows[n] == -1) {
            cows[n] = p;
        } else {
            if(cows[n] != p) {
                cows[n] ^= 1;
                ans++;
            }
        }
    }
    cout << ans << "\n";
}