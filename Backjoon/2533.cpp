#include <ios>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > g;
int cache[1000001][2];
vector<bool> visit;

int solve(int src, int now) {
    int& ret = cache[src][now];
    if(ret != -1) return ret;
    bool isLeaf = true;
    for(int next: g[src]) {
        if(!visit[next]) {
            isLeaf = false;
            break;
        }
    }
    if(isLeaf) {
        int ret = 0;
        if(now == 1) ret = 1;
        else ret = 0;
        return ret;
    }
    ret = now;
    for(int next: g[src]) {
        if(!visit[next]) {
            visit[next] = true;
            if(now == 0) {
                ret += solve(next, 1);
            } else {
                int ret1 = ret;
                ret1 += solve(next, 1);
                int ret2 = ret;
                ret2 += solve(next, 0);
                ret = min(ret1, ret2);
            }
            visit[next] = false;
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    g.assign(n+1, vector<int>());
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visit.assign(n+1, 0);
    visit[1] = true;
    int ret = min(solve(1, 0), solve(1, 1));
    cout << ret << "\n";
}
