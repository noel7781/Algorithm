#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int> > adj;
int cache [1000001][2];

int solve(int pos, int before, int adapt) {
    bool isEnd = true;
    for(auto next: adj[pos]) {
        if(next != before) {
            isEnd = false;
        }
    }
    if(isEnd) return 0;
    int& ret = cache[pos][adapt];
    if(ret != -1) return ret;
    ret = 1e9;
    if(adapt) {
        int tmp = 0;
        for(auto next: adj[pos]) {
            if(next == before) continue;
            tmp += min(1+solve(next, pos, 1), solve(next, pos, 0));
        }
        ret = tmp;
    } else {
        int tmp = 0;
        for(auto next: adj[pos]) {
            if(next == before) continue;
            tmp += (1+solve(next, pos, 1));
        }
        ret = tmp;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    adj.resize(N+1);
    for(int i = 0; i < N-1; i++) {
        int p1, p2; cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    cout << min(solve(1, 0, 0), 1+solve(1, 0, 1)) << "\n";
}