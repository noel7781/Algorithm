#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<vector<int> > g;
bool visit[10001];
int cache[10001][2];

int solve(int r, int p) {
    int& ret = cache[r][p];
    if(ret != -1) return ret;
    ret = 0;
    bool isLeaf = true;
    for(auto next:g[r]) {
        if(!visit[next]) {
            isLeaf = false;
            break;
        }
    }
    if(isLeaf) {
        if(p == 0) return ret = v[r];
        else if(p == 1) return ret = 0;
    }
    if(p == 1) {
        for(auto next:g[r]) {
            if(!visit[next]) {
                visit[next] = true;
                ret += solve(next, 0);
                visit[next] = false;
            }
        }
    } else {
        int ret1 = 0, ret2 = 0;
        ret1 += v[r];
        for(auto next:g[r]) {
            if(!visit[next]) {
                visit[next] = true;
                ret1 += solve(next, 1);
                ret2 += solve(next, 0);
                visit[next] = false;
            }
        }
        ret = max(ret1, ret2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    memset(visit, 0, sizeof(visit));
    cin >> n;
    v.resize(n+1);
    g.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visit[1] = true;
    int ret = solve(1, 0);
    cout << ret << "\n";
}
