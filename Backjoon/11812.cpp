#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K, Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> Q;
    while(Q--) {
        ll n1, n2; cin >> n1 >> n2;
        if(K == 1) {
            cout << max(n1, n2) - min(n1, n2) << "\n";
        } else {
            ll p = n1, q = n2;
            ll ret = 0;
            while(p != q) {
                if(p > q) {
                    p = (p + K - 2) / K;
                } else {
                    q = (q + K - 2) / K;
                }
                ret++;
            }
            cout << ret << "\n";
        }

    }
}