#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<vector<int> > adj;
vector<int> prv;
vector<bool> visit;
vector<bool> fin;
int counter = 0;

int dfs(int curr, int pre) {
    int ret = 1;
    visit[curr] = 1;
    for(int i = 0; i < adj[curr].size(); ++i) {
        int next = adj[curr][i];
        if(!visit[next]) {
            prv[next] = curr;
            ret = min(ret, dfs(next, curr));
        } else if(!fin[next] && next != pre) {
            ret = 0;
        }
    }
    fin[curr] = 1;
    return ret;
}

int solve() {
    prv = vector<int>(n, -1);
    visit = vector<bool>(n, 0);
    fin = vector<bool>(n, 0);
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        if(!visit[i]) {
            if(dfs(i, 0)) {
                ret += 1;
            }
        }
    }
    return ret;
}

int main() {
    int caseN = 1;
    while(1) {
        adj.clear();
        cin >> n >> m;
        adj.assign(n, vector<int>());
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; ++i) {
            int p1, p2; cin >> p1 >> p2;
            p1 -= 1; p2 -= 1;
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
        }
        int ret = solve();
        if(ret > 1) {
            cout << "Case " << caseN << ": A forest of " << ret << " trees.\n";
        } else if(ret == 1) {
            cout << "Case " << caseN << ": There is one tree.\n";
        } else {
            cout << "Case " << caseN << ": No trees.\n";
        }
        caseN += 1;
    }
}
