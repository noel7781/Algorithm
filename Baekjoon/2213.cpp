#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<int> w;
vector<vector<int> > g;
vector<bool> visit;
vector<int> path;
int cache[10001][2];

int get_indep(int src, int isSubset) {
    int& ret = cache[src][isSubset];
    if(ret != -1) return ret;
    ret = 0;
    if(isSubset) ret += w[src];
    for(int next: g[src]) {
        if(visit[next]) continue;
        visit[next] = 1;
        if(isSubset) {
            ret += get_indep(next, 0);
        }  else {
            int r1 = get_indep(next, 0), r2 = get_indep(next, 1);
            ret += max(r1, r2);
        }
        visit[next] = 0;
    }
    return ret;
}

void reconstruct(int src, int isSubset) {
    if(isSubset) path.push_back(src);
    for(int next: g[src]) {
        if(visit[next]) continue;
        visit[next] = 1;
        if(isSubset) {
            reconstruct(next, 0);
        } else {
            int r1 = get_indep(next, 0), r2 = get_indep(next, 1);
            if(r1 > r2) {
                reconstruct(next, 0);
            } else {
                reconstruct(next, 1);
            }
        }
    }
    return;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    visit.assign(n+1, 0);
    visit[1] = 1;
    int ret1 = get_indep(1, 0);
    int ret2 = get_indep(1, 1);
    if(ret1 > ret2) {
        reconstruct(1, 0);
    } else {
        reconstruct(1, 1);
    }
    int ret = max(ret1, ret2);
    cout << ret << "\n";
    sort(path.begin(), path.end());
    for(int it: path) {
        cout << it << " ";
    }
    cout << "\n";
}

int main() {
    cin >> n;
    w.resize(n+1); g.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
}
