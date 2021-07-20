#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll cache[31][31];

ll solve(ll n, ll k) {
    if(n == k) return 1;
    if(k == 0) return 1;
    ll& ret = cache[n][k];
    if(ret != -1) return ret;
    return ret = (solve(n-1, k-1) + solve(n-1, k));
}

int main() {
    memset(cache, -1, sizeof(cache));
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> k >> n;
        cout << solve(n, k)  << "\n";
    }
}