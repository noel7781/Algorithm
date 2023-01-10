#include <bits/stdc++.h>

using namespace std;

int MOD;
int primes[40000];
vector<int> v_primes;

void getPrimes() {
    for(int i = 2; i < 40000; i++) {
        primes[i] = 1;
    }
    for(int i = 2; i < 40000; i++) {
        if(primes[i]) {
            v_primes.push_back(i);
            for(int j = i; i*j < 40000; j++) {
                primes[i*j] = 0;
            }
        }
    }
}

int solve(int a, int p) {
    if(p == 1) return a;
    int tmp = solve(a, p/2) % MOD;
    int ret = ((long long)tmp * tmp) % MOD;
    if(p % 2) {
        ret = ((long long)ret * a) % MOD;
    }
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p = -1, a = -1;
    getPrimes();
    while(1) {
        cin >> p >> a;
        if(p == 0 && a == 0) return 0;
        MOD = p;
        bool isDivde = false;
        for(auto x: v_primes) {
            if(x >= p) break;
            if(p % x == 0) {
                isDivde = true;
                break;
            }
        }
        if(!isDivde) {
            cout << "no\n";
        } else if(solve(a, p) == a%p) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

}