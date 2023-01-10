#include <bits/stdc++.h>
using namespace std;
int N, M;
int check[10001];
int cache[10001][200];
int solve(int pos, int prev) {
    if(pos == N) return 0;
    int& ret = cache[pos][prev];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int j = -1; j <= 1; j++) {
        int next = prev + j;
        if(next > 0 && pos+next <= N && !check[pos+next]) {
            ret = min(ret, 1 + solve(pos+next, next));
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x; cin >> x;
        check[x] = 1;
    }
    int ans = solve(1, 0);
    if(ans >= 1e9) ans = -1;
    cout << ans;
    
}