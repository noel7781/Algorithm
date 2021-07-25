#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

ll cache[91];

ll solve(int k) {
    if(k <= 2) return 1;
    ll& ret = cache[k];
    if(ret != -1) return ret;
    ret = 0;
    for(int j = 2; j <= k; ++j) {
        ret += solve(k-j);
    }
    return ret;
}

int main() {
    memset(cache, -1 , sizeof(cache));
    int n; cin >> n;
    ll ret = solve(n);
    cout << ret << "\n";
}
