#include <iostream>
#include <cmath>
#include <vector>

#define MAX_NUM 1000001

using namespace std;

int n;
vector<int> v;
vector<int> all_primes;
int prime[MAX_NUM];
int score = 1;

void getPrime() {
    for(int i = 2; i < MAX_NUM; ++i) prime[i] = 1;

    for(int i = 2; i < MAX_NUM; ++i) {
        if(prime[i]) {
            all_primes.push_back(i);
        }
        for(long long j = i; i*j < (long long)MAX_NUM; ++j) {
            prime[i*j] = 0;
        }
    }
    return;
}

int countNumber(vector<int>& count, vector<int>& v, int p) {
    int total = 0;
    for(int i = 0; i < n; ++i) {
        int t = 0;
        while(v[i] % p == 0) {
            t += 1;
            v[i] /= p;
        }
        count[i] = t;
        total += t;
    }
    int ret = 0;
    if(total >= n) {
        int each_count = total / n;
        for(int i = 0; i < each_count; ++i) {
            score *= p;
        }
        for(int i = 0; i < n; ++i) {
            ret += max(0, each_count - count[i]);
        }
        return ret;
    } else {
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getPrime();
    cin >> n; v.assign(n, 0);
    for(auto &it: v) cin >> it;
    int ret = 0;
    for(int i = 0; i < all_primes.size(); ++i) {
        int cur_prime = all_primes[i];
        vector<int> count(n, 0);
        ret += countNumber(count, v, cur_prime);
    }
    cout << score << " " << ret << "\n";
}