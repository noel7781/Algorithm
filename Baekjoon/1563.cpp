#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MOD 1000000

using namespace std;

int cache[1001][3][4];
int N;

int solve(int day, int late, int absent) {
    if(late >= 2 || absent >= 3) return 0;
    if(day == N) return 1;
    int& ret = cache[day][late][absent];
    if(ret != -1) return ret;
    ret = 0;
    if(absent == 0) {
        ret += solve(day+1, late, absent);
        ret %= MOD;
        ret += solve(day+1, late, absent+1);
        ret %= MOD;
        ret += solve(day+1, late+1, absent);
        ret %= MOD;
    } else {
        ret += solve(day+1, late, 0);
        ret %= MOD;
        ret += solve(day+1, late, absent+1);
        ret %= MOD;
        ret += solve(day+1, late+1, 0);
        ret %= MOD;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    int ret = solve(0, 0, 0);
    cout << ret % MOD << "\n";
}
