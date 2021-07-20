#include <iostream>
#include <cstring>

using namespace std;

int cache[1001][1001];

int MOD = 10007;

int solve(int n, int k) {
    if(n == k) return 1;
    if(k == 0) return 1;
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    return ret = (solve(n-1, k-1) + solve(n-1, k)) % 10007;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k; cin >> n >> k;
    cout << solve(n, k) % 10007 << "\n";
}