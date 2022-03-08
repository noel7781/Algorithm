#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime[5000001];
int factor[5000001];
void setPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    memset(factor, 0x3f, sizeof(factor));
    for(int i = 2; i < 5000001; i++) {
        if(isPrime[i]) {
            factor[i] = i;
            for(ll j = (ll)i*i; j < 5000001; j += i) {
                factor[j] = min(factor[j], i);
                isPrime[j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setPrime();
    ll n; cin >> n;
    while(n--) {
        int k; cin >> k;
        while(k > 1) {
            cout << factor[k] << " ";
            k /= factor[k];
        }
        cout << "\n";
    }
}