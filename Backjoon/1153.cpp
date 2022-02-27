#include <bits/stdc++.h>

using namespace std;

int primes[1000001];
vector<int> v_primes;
int is_find = 0;

void getPrime(int n) {
    primes[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            v_primes.push_back(i);
            for(int j = 2; i*j <= n; j++) {
                primes[i*j] = 0;
            }
        }
    }

}

void solve(vector<int>& v, int sum, int left, int pos) {
    if(is_find) return;
    if(left == 1) {
        if(primes[sum]) {
            v.push_back(sum);
            is_find = true;
            for(auto x: v) {
                cout << x << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(int i = pos; i < (int)v_primes.size(); i++) {
        if(sum < v_primes[i]) break;
        v.push_back(v_primes[i]);
        solve(v, sum-v_primes[i], left-1, i);
        if(is_find) return;
        v.pop_back();
    }
}

int main() {
    for(int i = 2; i <= 1000000; i++) {
        primes[i] = 1;
    }
    int N; cin >> N;
    getPrime(N);
    vector<int> v;
    solve(v, N, 4, 0);
    if(!is_find) {
        cout << -1 << "\n";
    }
}