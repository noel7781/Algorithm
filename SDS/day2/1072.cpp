#include <iostream>

using namespace std;

typedef long long ll;

ll X, Y;
ll Z;
bool check(ll thr) {
    ll n_X = X + thr;
    ll n_Y = Y + thr;
    ll n_Z = n_Y * 100 / n_X;
    if(n_Z  > Z) return true;
    return false;
}

int main() {
    cin >> X >> Y;
    Z = Y * 100 / X;
    if(X == Y || Z >= 99) {
        cout << -1 << "\n";
        return 0;
    }
    ll lo = 0, hi = 1e9;
    while(lo+1 < hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}