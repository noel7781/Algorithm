#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factorSimple(int n) {
    vector<int> ret;
    int sqrtn = int(sqrt(n));
    for(int div = 2; div <= sqrtn; ++div) {
        while(n % div == 0) {
            n /= div;
            ret.push_back(div);
        }
    }
    if(n > 1) ret.push_back(n);
    return ret;
}

const int MAX_N = 1000;
int n;
bool isPrime[MAX_N+1];

void eratosthenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    int sqrtn = int(sqrt(n));
    for(int i = 2; i <= sqrtn; ++i) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int minFactor[MAX_N];

void eratosthenes2() {
    minFactor[0] = minFactor[1] = -1;
    for(int i = 2; i <= n; ++i) {
        minFactor[i] = i;
    }
    int sqrtn = int(sqrt(n));
    for(int i = 2; i <= sqrtn; ++i) {
        if(minFactor[i] == i) {
            for(int j = i*i; j <= n; j += i) {
                if(minFactor[j] == j)
                    minFactor[j] = i;
            }
        }
    }
}

vector<int> factor(int n) {
    vector<int> ret;
    while(n > 1) {
        ret.push_back(minFactor[n]);
        n /= minFactor[n];
    }
    return ret;
}
