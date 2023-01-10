#include <iostream>

using namespace std;

typedef long long ll;

int T;

ll solve(ll k) {
    ll lo = 1, hi = 1e5;
    ll ret = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(mid * mid > k) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
            ret = max(ret, mid);
        }
    }
    if(ret * ret+ 1 < k && k < ((ret+1)*(ret+1) -(ret+1) + 1)) {
        return 2 * ret;
    }
    if(ret * ret+ 1 < k) {
        return 2 * ret + 1;
    }
    if(ret * ret == k) {
        return 2 * ret - 1;
    }
    return 2 * ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    while(T--) {
        ll a, b; cin >> a >> b;
        cout << solve(b-a) << "\n";
    }
}
