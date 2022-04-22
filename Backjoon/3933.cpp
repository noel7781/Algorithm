#include <bits/stdc++.h>
using namespace std;
#define MAXVALUE (1 << 15)
vector<int> v;
int cache[MAXVALUE+1][200][5];
int solve(int sum, int pos, int left) {
    if(sum == 0) return 1;
    if(pos >= v.size()) return 0;
    if(left == 0 || v[pos] > sum) return 0;
    int& ret = cache[sum][pos][left];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(sum, pos+1, left);
    if(v[pos] <= sum) {
        ret += solve(sum-v[pos], pos, left-1);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    for(int k = 1; k * k <= MAXVALUE; k++) {
        v.push_back(k*k);
    }
    int st = -1;
    while(1) {
        cin >> st;
        if(!st) break;
        cout << solve(st, 0, 4) << "\n";
    }
    return 0;
}