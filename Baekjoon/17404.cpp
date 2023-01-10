#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > costs;

int cache[1002][3][3];

int solve(int h, int idx, int start) {
    if(h == N-1) return 0;
    int& ret = cache[h][idx][start];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int j = 0; j < 3; j++) {
        if(j != idx && h != N-2) ret = min(ret, costs[h+1][j]+solve(h+1, j, start));
        else if(j != idx && j != start) ret = min(ret, costs[h+1][j]+solve(h+1, j, start));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N; costs.resize(N+1, vector<int>(3, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> costs[i][j];
        }
    }
    int ret = 1e9;
    for(int i = 0; i < 3; i++) {
        ret = min(ret, costs[0][i]+solve(0, i, i));
    }
    cout << ret << "\n";
}