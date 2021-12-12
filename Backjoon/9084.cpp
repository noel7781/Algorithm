#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
int cache[21][10001];

int solve(int pos, int target) {
    if(target == 0) return 1;
    if(pos >= n) return 0;
    int& ret = cache[pos][target];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i*v[pos] <= target ; i++) {
        ret += solve(pos+1, target - i*v[pos]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        v.clear();
        cin >> n; v.assign(n, 0);
        for(auto &it: v) cin >> it;
        int m; cin >> m;
        cout << solve(0, m) << "\n";

    }
}
