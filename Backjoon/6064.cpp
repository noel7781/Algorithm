#include <bits/stdc++.h>
using namespace std;
int M, N, X, Y;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> M >> N >> X >> Y;
        int ret = 0;
        int cx = 1, cy = 1;
        ret += X;
        cx = X;
        cy += (X-1);
        cy %= N;
        if(cy == 0) cy = N;
        int cnts = 0;
        while(cy != Y) {
            if(cnts >= N+1) {
                break;
            }
            cy += M;
            cy %= N;
            if(cy == 0) cy = N;
            cnts++;
        }
        if(cnts >= N+1) {
            cout << -1 << "\n";
        } else {
            cout << ret + cnts*M << "\n";
        }
    }
}