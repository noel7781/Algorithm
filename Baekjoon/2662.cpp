#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<vector<pii> > V;
int cache[301][21];
int solve(int left, int pos) {
    int& ret = cache[left][pos];
    if(pos == M) return ret = 0;
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, solve(left, pos+1));
    for(auto [cost, profit]: V[pos]) {
        if(cost <= left) {
            ret = max(ret, profit + solve(left-cost, pos+1));
        }
    }
    return ret;
}
void find_path(int left, int pos, vector<int>& path) {
    if(pos == M) return;
    if(cache[left][pos+1] == cache[left][pos]) {
        path.push_back(0);
        find_path(left, pos+1, path);
        return;
    }
    for(auto [cost, profit]: V[pos]) {
        if(left < cost) continue;
        if(profit + cache[left-cost][pos+1] == cache[left][pos]) {
            path.push_back(cost);
            find_path(left-cost, pos+1, path);
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    V.resize(M);
    for(int i = 1; i <= N; i++) {
        int cost; cin >> cost;
        for(int j = 0; j < M; j++) {
            int profit; cin >> profit;
            V[j].push_back({cost, profit});
        }
    }
    int ret = solve(N, 0);
    cout << ret << "\n";
    vector<int> path;
    find_path(N, 0, path);
    for(auto it: path) {
        cout << it << " ";
    }
    cout << "\n";
}