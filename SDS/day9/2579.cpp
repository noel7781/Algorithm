#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> v;
int cache[301][4];

int solve(int pos, int cont) {
    if(pos == n && cont < 3) return v[pos];
    if(pos > n || cont >= 3) return -1e9;
    int& ret = cache[pos][cont];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, v[pos]+solve(pos+1, cont+1));
    ret = max(ret, v[pos]+solve(pos+2, 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.assign(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int ret = max(solve(1, 1), solve(2, 1));
    cout << ret << "\n";
}