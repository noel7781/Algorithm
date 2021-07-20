#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int cache[101];

int solve(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    int& ret = cache[n];
    if(ret != -1)
        return ret;
    return ret = ((solve(n-1)) % MOD + (solve(n-2) % MOD)) % MOD;
    
}

int main() {
    int cnt; cin >> cnt;
    while(cnt--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << solve(n) << "\n";
    }
}
