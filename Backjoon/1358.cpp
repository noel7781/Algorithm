#include <bits/stdc++.h>
using namespace std;
int W, H, X, Y, P;
int R;
int inRange(int p, int q) {
    p -= X; q -= Y;
    return ((p)*(p) + (R-q)*(R-q) <= R*R) || (0 <= p && p <= W && 0 <= q && q <= H) || ((W-p)*(W-p) + (R-q)*(R-q) <= R*R);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> W >> H >> X >> Y >> P;
    R = H / 2;
    int ret = 0;
    for(int i = 0; i < P; i++) {
        int p, q; cin >> p >> q;
        ret += inRange(p, q);
    }
    cout << ret << "\n";
}