#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > V;
int cache[100001][3];
int solve(int pos, int ord) {
    if(pos == N-1 && ord == 1) {
        return V[pos][ord];
    }
    if(pos >= N) return 1e9;
    int& ret = cache[pos][ord];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int j = -1; j <= 1; j++) {
        int nxt = ord + j;
        if(nxt >= 0 && nxt <= 2) {
            ret = min(ret, V[pos][ord] + solve(pos+1, nxt));
        }
    }
    if(ord < 2) {
        ret = min(ret, V[pos][ord] + solve(pos, ord+1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(1) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        if(N == 0) return 0;
        V.resize(N, vector<int>(3, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 3; j++) {
                int x; cin >> x; V[i][j] = x;
            }
        }
        cout << t << ". " << solve(0, 1) << "\n";
        t++;
    }
}