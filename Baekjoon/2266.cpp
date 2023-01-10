#include <bits/stdc++.h>
using namespace std;
int N, K;
int cache[501][501];
int solve(int lo, int hi, int K) {
    if(lo==hi) return 1;
    if(K == 1) return hi-lo+1;
    int& ret = cache[hi-lo][K];
    if(ret != -1) return ret;
    ret = 0;
    for(int h = lo; h <= hi; h++) {
        if(ret == 0) ret = max(solve(lo, h-1, K-1), solve(h+1, hi, K))+1;
        else ret = min(ret, max(solve(lo, h-1, K-1), solve(h+1, hi, K))+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    int ret = 0;
    cout << solve(1, N, K) << "\n";
}