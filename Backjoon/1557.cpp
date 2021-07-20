#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAXN ll(1e12)

using namespace std;

typedef long long ll;


ll k;
vector<bool> isPrime(sqrt(MAXN)+2, 1);
vector<ll> sqPrimes;

void getPrime() {
    ll limit = sqrt(MAXN)+1;
    for(ll i = 2; i <= limit; ++i) {
        if(isPrime[i]) {
            cout<<"i: "<<i<<endl;
            sqPrimes.push_back(i*i);
            for(ll j = i*i; j <= limit; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

bool cnt(ll value) {
    ll count = 0;
    for(auto it: sqPrimes) {
        if(value < it) break;
        ll adder = value / it;
        count += adder;
    }
    ll comp = value - count;
    if(comp >= k) return true;
    return false;
}

int main() {
    getPrime();
    cin >> k;
    ll lo = 0, hi = MAXN;
    while(lo+1 < hi) {
        ll mid = (lo+hi) >> 1;
        if(cnt(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}
