#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, k;

int dfs(vector<vector<int> >& g, int idx, vector<bool>& visit, vector<int>& check) {
    if(check[idx]) return 1;
    if(visit[idx]) return 0;
    visit[idx] = true;
    check[idx] = 1;
    int ret = 0;
    for(auto next: g[idx]) {
        ret |= dfs(g, next, visit, check);
    }
    check[idx] = 0;
    return ret;
}

bool isCycle(vector<vector<int> >& g) {
    vector<bool> visit(n+1, 0);
    vector<int> check(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!visit[i])
            if(dfs(g, i, visit, check)) {
                return true;
            }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t_num; cin >> t_num;
    for(int test_case = 1; test_case <= t_num; ++test_case) {
        cin >> n >> m >> k;
        vector<vector<int> > g(n+1, vector<int>());
        vector<vector<int> > unk(n+1, vector<int>());
        for(int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
        }
        string ret = "";
        for(int i = 0; i < k; ++i) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            if(isCycle(g)) {
                g[a].pop_back();
                g[b].push_back(a);
                ret += "1";
            } else {
                ret += "0";
            }
        }
        cout << "Case #" << test_case << "\n";
        cout << ret << "\n";
    }
}
