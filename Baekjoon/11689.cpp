#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime[1000001];
vector<int> primes;
void setPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i < 1000005; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(ll j = (ll)i*i; j < 1000005; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setPrime();
    ll n; cin >> n;
    ll sqrtn = sqrt(n);
    ll ret = n;
    for(auto prime: primes) {
        if(prime > n) break;
        if(n % prime == 0) {
            ret /= prime;
            ret *= (prime-1);
            while(n % prime == 0) n /= prime;
        }
    }
    if(n >= 1e6) {
        ret /= n;
        ret *= (n-1);
    }
    cout << ret << "\n";
}