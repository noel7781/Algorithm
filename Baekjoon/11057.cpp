#include <iostream>
#include <cstring>

#define MOD 10007

using namespace std;

int cache[1041][1041];

int Comb(int n, int r) {
    if(n == r || r == 0) return 1;
    int& ret = cache[n][r];
    if(ret != -1) return ret;
    return ret = (Comb(n-1, r) % MOD + Comb(n-1, r-1) % MOD) % MOD;
}

int H(int k) {
    return Comb((10 + k - 1), k) % MOD;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    int ret = H(n);
    cout << ret << "\n";
}
