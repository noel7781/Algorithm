#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int D[21][21];
int cache[21][(1<<20)+1];

int solve(int y, int use) {
    if(y == n) return 0;
    int& ret = cache[y][use];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int x = 0; x < n; ++x) {
        if(!(use & (1 << x)))
            ret = min(ret, D[y][x] + solve(y+1, use | (1 << x)));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> D[i][j];
        }
    }
    cout << solve(0, 0) << "\n";
}
