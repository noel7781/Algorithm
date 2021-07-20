#include <iostream>
#include <vector>
#include <cstring>

#define MOD 10000000

using namespace std;

int t;
int cache[101][101];


int solve(int n, int first) {
    if(n == first)
        return 1;
    int& ret = cache[n][first]; 
    if(ret != -1)
        return ret;
    ret = 0;
    for(int second = 1; second <= n - first; ++second) {
        int add = first + second - 1;
        add *= solve(n-first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        int ret = 0;
        for(int start = 1; start <= n; ++start) {
            ret += solve(n, start);
            ret %= MOD;
        }
        cout << ret << "\n";
    }
}
