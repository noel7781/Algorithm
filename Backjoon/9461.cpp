#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll cache[101];

ll solve(int k) {
    if(k==1 || k==2 || k==3)
        return 1;
    if(k==4 || k == 5)
        return 2;
    ll& ret = cache[k];
    if(ret != -1)
        return ret;
    return ret = solve(k-1) + solve(k-5);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << solve(n) << "\n";
    }
}
