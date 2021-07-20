
#include <iostream>
#include <cmath>
#include <vector>

#define MAX_NUM 4000001

using namespace std;

int n;
vector<int> v;
vector<int> all_primes;
int prime[MAX_NUM];

void getPrime() {
    for(int i = 2; i < MAX_NUM; ++i) prime[i] = 1;

    for(int i = 2; i < MAX_NUM; ++i) {
        if(prime[i] == 1) {
            all_primes.push_back(i);
        }
        for(long long j = i; i*j < (long long)MAX_NUM; ++j) {
            prime[i*j] = 0;
        }
    }
    return;
}

bool isOk(int n, int i) {
    if(i == all_primes.size()) return false;
    n -= all_primes[i];
    if(n == 0) return true;
    else {
        if(n < all_primes[i+1]) return false;
        else return isOk(n, i+1);
    }
}

int main() {
    getPrime();
    cin >> n;
    int ret = 0;
    for(int i = 0; i < all_primes.size(); ++i) {
        if(isOk(n, i)) {
            ret += 1;
        }
    }
    cout << ret << "\n";
}