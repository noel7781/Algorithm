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