#include <bits/stdc++.h>
#define MOD 1000000000;
using namespace std;
int N, K;
int cache[201][201];
int solve(int left, int cnt) {
    if(left == 0 && cnt == 0) return 1;
    if(cnt < 0) return 0;
    int& ret = cache[left][cnt];
    if(ret != -1) return ret;
    ret = 0;
    for(int k = 0; k <= N; k++) {
        if(left >= k) {
            ret += solve(left - k, cnt - 1);
            ret %= MOD;
        }
    }
    ret %= MOD;
    return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    cout << solve(N, K) << "\n";
}