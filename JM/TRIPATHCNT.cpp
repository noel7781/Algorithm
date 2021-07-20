#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int t;
int n;
ll path[101][101];
ll cache[101][101];
ll countCache[101][101];

ll solve(int y, int x) {
    if(y == n) return 0;
    ll& ret = cache[y][x];
    if(ret != -1)
        return ret;
    ret = max(path[y][x] + solve(y+1, x), path[y][x] + solve(y+1, x+1));
    return ret;
}

ll count_ret(int y, int x) {
    if(y == n-1)
        return 1;
    ll& ret = countCache[y][x];
    if(ret != -1)
        return ret;
    ret = 0;
    ll left = cache[y+1][x];
    ll right = cache[y+1][x+1];
    if(left == right) 
        return ret = count_ret(y+1, x) + count_ret(y+1, x+1);
    else if(left > right)
        return ret = count_ret(y+1, x);
    else
        return ret = count_ret(y+1, x+1);
}

int main() {
    cin >> t;
    while(t--) {
        memset(path, 0, sizeof(path));
        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));
        cin >> n;
        int cnt = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < cnt; ++j) {
                cin >> path[i][j];
            }
            cnt += 1;
        }
        solve(0, 0);
        cout << count_ret(0, 0) << "\n";
    }
}
