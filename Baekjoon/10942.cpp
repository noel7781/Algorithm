#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int cache[2005][2005];
vector<int> v;

int solve(int p, int q) {
    if(p == q) return 1;
    if(q-p == 1) {
        if(v[q] == v[p]) return 1;
        return 0;
    }
    int& ret = cache[p][q];
    if(ret != -1) return ret;
    return ret = (v[p] == v[q] && solve(p+1, q-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int p, q; cin >> p >> q;
        cout << solve(p, q) << "\n";
    }
}