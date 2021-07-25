#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[100001];
vector<int> sq_num;

int solve(int n) {
    if(n < 0) return 1e9;
    if(n == 0) return 0;
    if(n == 1) return 1;
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int now: sq_num) {
        ret = min(ret, 1+solve(n-now));
    }
    return ret;
}

int main() {
    int n; cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= 400; ++i) {
        if(i*i <= n) sq_num.push_back(i*i);
    }
    int ret = solve(n);
    cout << ret << "\n";
}
