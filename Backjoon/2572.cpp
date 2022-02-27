#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int N;
vector<char> colors;
int M, K;
vector<vector<pair<int, char> > > board;
int cache[MAXN][501];
int solve(int pos, int place) {
    if(pos == N) return 0;
    int& ret = cache[pos][place];
    if(ret != -1) return ret;
    ret = 0;
    for(auto next: board[place]) {
        if(next.second == colors[pos]) {
            ret = max(ret, 10+solve(pos+1, next.first));
        } else {
            ret = max(ret, solve(pos+1, next.first));
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    colors.resize(N);
    for(auto &it: colors) cin >> it;
    cin >> M >> K;
    board.resize(M+1);
    for(int i = 0; i < K; i++) {
        int n1, n2; char clr; cin >> n1 >> n2 >> clr;
        board[n1].push_back({n2, clr});
        board[n2].push_back({n1, clr});
    }
    cout << solve(0, 1) << "\n";
}