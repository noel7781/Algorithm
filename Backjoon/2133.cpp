#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
ll cache[31];

ll solve(int n) {
    if(n == 1) return 0;
    if(n == 2) return 3;
    if(n == 3) return 0;
    ll& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    ret += 3 * solve(n-2);
    for(int k = 4; k < n; k += 2) {
        ret += solve(n - k);
    }
    ret += 2;
    return ret;

}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(n) << "\n";
}
