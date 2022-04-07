#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int N, K;
int cache[10001][5001];
int comb(int n, int k) {
    if(k == 0 || k == n) return 1;
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    ret += comb(n-1, k);
    ret %= MOD;
    ret += comb(n-1, k-1);
    ret %= MOD;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    cout << comb(N+K-1, N) << "\n";
    return 0;
}