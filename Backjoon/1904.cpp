#include <iostream>
#include <cstring>

using namespace std;

int cache[1000001];

int solve(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    int& ret = cache[n];
    if(ret != -1)
        return ret;
    return ret = (solve(n-1) + solve(n-2)) % 15746;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(n) << "\n";
}
