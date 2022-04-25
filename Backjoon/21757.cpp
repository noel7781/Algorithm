#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> V;
int psum[100002];
ll cache[100002][5];
ll solve(int pos, int left) {
    if(left == 0 && pos == 0) return 1LL;
    if(left == 0) return 0LL;
    ll& ret = cache[pos][left];
    if(ret != -1) return ret;
    ret = 0;
    for(int p = 0; p < pos; p++) {
        if(psum[pos] - psum[p] == psum[N]/4) {
            ret += solve(p, left-1);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N; V.resize(N+1); 
    for(int i = 1; i <= N; i++) {
        cin >> V[i];
        psum[i] = psum[i-1] + V[i];
    }
    int total = psum[N];
    if(total % 4) {
        cout << 0 << "\n";
        return 0;
    }
    int part = total / 4;
    ll ret = solve(N, 4);
    cout << ret << "\n";
}