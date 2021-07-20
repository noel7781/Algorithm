#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000003

using namespace std;

int n, k;
int d[1012][1012];

int solve() {
    for(int i = 1; i <= n; ++i) {
        d[i][1] = i;
        d[i][0] = 1;
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= k; ++j) {
            d[i][j] = d[i-2][j-1] + d[i-1][j];
            d[i][j] %= MOD;
        }
    }
    int ret = (d[n-3][k-1] + d[n-1][k]) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cout << solve() << "\n";
}
