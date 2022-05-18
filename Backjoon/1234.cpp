#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, R, G, B;
ll comb[11][11];
ll cache[11][101][101][101];
ll nCr(int n, int r) {
    if(n == r || r == 0) return 1LL;
    ll& ret = comb[n][r]; 
    if(ret != -1) return ret;
    ret = nCr(n-1, r) + nCr(n-1, r-1);
    return ret;
}

ll solve(int f, int r, int g, int b) {
    if(r < 0 || g < 0 || b < 0) return 0;
    if(f == N+1) return 1LL;
    ll& ret = cache[f][r][g][b];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(f+1, r-f, g, b);
    ret += solve(f+1, r, g-f, b);
    ret += solve(f+1, r, g, b-f);
    if(f % 2 == 0) {
        ll factor = nCr(f, f/2);
        ret += factor*solve(f+1, r-f/2, g-f/2, b);
        ret += factor*solve(f+1, r-f/2, g, b-f/2);
        ret += factor*solve(f+1, r, g-f/2, b-f/2);
    }
    if(f % 3 == 0) {
        int d = f/3;
        ll factor = nCr(f, d) * nCr(f-d,d) * nCr(f-2*d, d);
        ret += factor*solve(f+1, r-f/3, g-f/3, b-f/3);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(comb, -1, sizeof(comb));
    memset(cache, -1, sizeof(cache));
    cin >> N >> R >> G >> B;
    cout << solve(1, R, G, B) << "\n";
}