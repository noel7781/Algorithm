#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
vector<vector<int> > adj;
int cache[10001][2];
int is_visit[10001];
int solve(int curr, int p) {
    bool is_leaf = true;
    for(const int& next: adj[curr]) {
        if(!is_visit[next]) {
            is_leaf = false;
            break;
        }
    }
    if(is_leaf) {
        if(p) return 0;
        else return V[curr];
    }
    int& ret = cache[curr][p];
    if(ret != -1) return ret;
    ret = 0;
    int tmp_ret = 0;
    if(!p) {
        tmp_ret = V[curr];
        for(const int& next: adj[curr]) {
            if(!is_visit[next]) {
                is_visit[next] = 1;
                tmp_ret += solve(next, 1);
                is_visit[next] = 0;
            }
        }
        ret = max(ret, tmp_ret);
    }
    tmp_ret = 0;
    for(const int& next: adj[curr]) {
        if(!is_visit[next]) {
            is_visit[next] = 1;
            tmp_ret += solve(next, 0);
            is_visit[next] = 0;
        }
    }
    ret = max(ret, tmp_ret);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    V.resize(N);
    adj.resize(N);
    for(auto &it: V) cin >> it;
    for(int i = 0; i < N-1; i++) {
        int p1, p2; cin >> p1 >> p2;
        adj[p1-1].push_back(p2-1);
        adj[p2-1].push_back(p1-1);
    }
    is_visit[0] = 1;
    cout << solve(0, 0) << "\n";
}