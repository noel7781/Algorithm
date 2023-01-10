#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int cache[100002][2];
int solve(int pos, int skipped) {
    if(pos == N+1) return 0;
    int &ret = cache[pos][skipped];
    if(ret != -1001) return ret;
    ret = V[pos];
    ret = max(ret, V[pos] + solve(pos+1, skipped));
    if(skipped < 1) ret = max(ret, solve(pos+1, skipped+1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < 100002; i++) for(int j = 0; j < 2; j++) cache[i][j] = -1001;
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    V.push_back(-10000);
    int ret = -1e9;
    for(int i = 0; i < N; i++) {
        ret = max(ret, solve(i, 0));
    }
    cout << ret << "\n";
}