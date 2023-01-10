#include <bits/stdc++.h>

#define MOD 9901

using namespace std;

int cache[100001];

int solve(int N) {
    if(N==0) return 1;
    if(N==1) return 3;
    int& ret = cache[N];
    if(ret != -1) return ret;
    ret = 0;
    ret += 2*solve(N-1);
    ret %= MOD;
    ret += solve(N-2);
    ret %= MOD;
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int N; cin >> N;
    cout << solve(N) << "\n";

}