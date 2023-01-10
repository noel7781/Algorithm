#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll A, B; cin >> A >> B;
    ll g = gcd(A, B);
    for(ll i = 0; i < g; i++) {
        cout << 1;
    }
    cout << "\n";
    return 0;
}