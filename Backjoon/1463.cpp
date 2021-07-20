#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1000001];

int solve(int n) {
    if(n==1)
        return 0;
    int& ret = cache[n];
    if(ret != -1)
        return ret;
    ret = 1e9;
    if(n % 3 == 0)
        ret = min(ret, 1+solve(n/3));
    if(n % 2 == 0)
        ret = min(ret, 1+solve(n/2));
    ret = min(ret, 1+solve(n-1));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(n) << "\n";
}
