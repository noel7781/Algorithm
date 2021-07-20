#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int v[8];

void solve(int ret[], vector<bool>& visit, int count) {
    if(count == m) {
        for(int i = 0; i < m; ++i) {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }
    int prev = -1;
    for(int i = 0; i < n; ++i) {
        if(visit[i]) continue;
        if(prev == v[i]) continue;
        prev = v[i];
        visit[i] = 1;
        ret[count] = v[i];
        solve(ret, visit, count+1);
        visit[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v, v+n);
    int ret[8];
    vector<bool> visit(n, 0);
    solve(ret, visit, 0);
}