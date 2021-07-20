#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int k, n;

int main() {
    cin >> k >> n;
    vector<ll> primes(k);
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 0; i < k; ++i) {
        cin >> primes[i];
        pq.push(primes[i]);
    }
    ll top = 0;
    for(int i = 0; i < n; ++i) {
        top = pq.top();
        pq.pop();
        for(int j = 0; j < k; ++j) {
            pq.push(top*primes[j]);
            if(top % primes[j] == 0) break;
        }
    }
    cout << top << "\n";
    return 0;
}