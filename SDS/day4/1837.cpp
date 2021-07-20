#include <iostream>
#include <vector>
#include <cstring>

#define MAX_NUM 1000001

using namespace std;

typedef long long ll;

ll prime[MAX_NUM+1];

vector<ll> primes;

void getPrime(int k) {
    for(int i = 0; i < k; ++i) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;

    for(ll i = 2; i < k; ++i) {
        if(prime[i]) primes.push_back(i);
        for(ll j = i; i*j < k; j+=1) {
            prime[i*j] = 0;
        }
    }
}

bool divide(string str, int p) {
    int sum = 0;
    for(int i = 0; i < str.size(); ++i) {
        sum = (sum * 10 + (str[i] - '0')) % p;
    }
    if(sum == 0) return true;
    else return 0;
}

int main() {
    string p; int k;
    cin >> p >> k;
    getPrime(k);
    for(int i = 0; i < primes.size() && primes[i] < k; ++i) {
        int prime = primes[i];
        bool ret = divide(p, prime);
        if(ret) {
            cout << "BAD " << prime << "\n";
            return 0;
        }
    }
    cout << "GOOD\n";
}