#include <bits/stdc++.h>
using namespace std;
int N, W, H;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W >> H;
    int lim = W * W + H * H;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x * x <= lim) cout << "DA\n";
        else cout << "NE\n";
    }
}