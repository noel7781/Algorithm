#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> V;
int cache[101][2048];
void solve(int used, int acc) {
    if(used == M+1) return;
    int& ret = cache[used][acc];
    if(ret != -1) return;
    ret = 1;
    for(int i = 0; i < N; i++) {
        solve(used+1, acc ^ V[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    V.resize(N);
    for(auto &it: V) { 
        cin >> it;
        it = abs(it);
    }
    solve(0, 0);
    for(int i = 1023; i > 0; i--) {
        if(cache[M][i] == 1) {
            cout << i << "\n";
            return 0;
        }
    }
}
