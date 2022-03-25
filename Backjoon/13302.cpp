#include <bits/stdc++.h>
using namespace std;
int N, M;
bool flags[101];
int cache[102][50];
int solve(int pos, int coupons) {
    if(pos > N) return 0;
    int& ret = cache[pos][coupons];
    if(ret != -1) return ret;
    ret = 1e9;
    if(flags[pos] == 0) {
        ret = solve(pos+1, coupons);
    } else {
        if(coupons >= 3) ret = min(ret, solve(pos+1, coupons-3));
        ret = min(ret, 10000+solve(pos+1, coupons));
        ret = min(ret, 25000+solve(pos+3, coupons+1));
        ret = min(ret, 37000+solve(pos+5, coupons+2));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    memset(flags, 1, sizeof(flags));
    for(int i = 0; i < M; i++) {
        int x; cin >> x; flags[x] = 0;
    }
    cout << solve(1, 0) << "\n";
}