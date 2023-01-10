#include <ios>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<vector<int> > v;
int cache[100001][2];

int solve(int n, int h) {
    if(n == 0) return 0;
    if(n < 0) return -1e9;
    int& ret = cache[n][h];
    if(ret != -1) return ret;
    ret = max(solve(n-2, h), solve(n-2, h^1));
    ret = max(ret, solve(n-1, h^1));
    ret += v[n][h];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        v.assign(n+1, vector<int>(2, 0));
        for(int i = 1; i <= n; ++i) {
            cin >> v[i][0];
        }
        for(int i = 1; i <= n; ++i) {
            cin >> v[i][1];
        }
        cout << max(solve(n, 0), solve(n, 1)) << "\n";
    }
}
