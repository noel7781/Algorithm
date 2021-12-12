#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
vector<int> v;
int cache[100001];

int solve(int k) {
    if(k < 0) return 1e9;
    if(k == 0) return 0;
    int& ret = cache[k];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int x: v) {
        ret = min(ret, 1+solve(k-x));
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    v.assign(n, 0);
    for(auto &it: v) cin >> it;
    int ret = solve(k);
    if(ret >= 1e9) ret = -1;
    cout << ret << "\n";
}
