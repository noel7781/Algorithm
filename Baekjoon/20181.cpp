#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; ll K;
vector<ll> V;
ll dp[100002];
ll psum[100002];
ll solve(int pos) {
    if(pos > N) return 0;
    ll& ret = dp[pos]; if(ret != -1) return ret;
    ret = solve(pos+1);
    ll eaten = 0;
    int lo = pos-1, hi = N+1;
    int mid;
    while(lo+1 < hi) {
        mid = lo+hi>>1;
        if(psum[mid]-psum[pos-1] >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    if(hi <= N) {
        ret = max(ret, psum[hi]-psum[pos-1]-K+solve(hi+1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    psum[0] = 0;
    V.resize(N+1); 
    for(int i = 1; i <= N; i++) {
        cin >> V[i];
        psum[i] = psum[i-1] + V[i];
    }
    cout << solve(1) << "\n";
    
}