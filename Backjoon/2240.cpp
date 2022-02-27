#include <bits/stdc++.h>

using namespace std;
int T, W;
vector<int> V;
int cache[1001][31][2];
int solve(int time, int move, int pos) {
    if(time == T) return 0;
    int& ret = cache[time][move][pos];
    if(ret != -1) return ret;
    if(V[time] == pos) {
        ret = 1+solve(time+1, move, pos);
        if(move > 0) ret = max(ret, solve(time+1, move-1, pos^1));
    } else {
        ret = solve(time+1, move, pos);
        if(move > 0)  ret = max(ret, 1+solve(time+1, move-1, pos^1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> T >> W;
    V.resize(T);
    for(auto &it: V) {
        cin >> it;
        it--;
    }
    int ret = solve(0, W, 0);
    cout << ret << "\n";
}