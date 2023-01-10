#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;
bool isPrime[int(1e7)+1];
vector<ll> primes;

void getPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(ll i = 2; i <= 1e7; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(ll j = i*i; j <= 1e7; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}
int main() {
    cin >> A >> B;
    getPrime();
    int ans = 0;
    for(ll n: primes) {
        ll cmp = n;
        while(cmp <= B / n) {
            cmp *= n;
            if(cmp >= A) ans++;
        }
    }
    cout << ans;
}