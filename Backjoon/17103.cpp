#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000001];
void getPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = 0; isPrime[1] = 0;
    for(int i = 2; i <= 1000; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= 1000000; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}
int solve(int x) {
    if(x == 4) return 1;
    int ret = 0;
    for(int j = 3; j <= x/2; j+=2) {
        if(isPrime[j] && isPrime[x-j]) ret++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    getPrime();
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << solve(x) << "\n";
    }
}