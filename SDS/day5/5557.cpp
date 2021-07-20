#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
ll cache[101][22];

ll solve(vector<int>& v, int pos, int sum) {
    if(pos == n-1) {
        if(sum == v[pos]) {
            return 1;
        }
        return 0;
    } else {
        ll& ret = cache[pos][sum];
        if(ret != -1) return ret;
        ret = 0;
        if(sum + v[pos] <= 20) {
            ret += solve(v, pos+1, sum+v[pos]);
        }
        if(sum - v[pos] >= 0) {
            ret += solve(v, pos+1, sum-v[pos]);
        }
        return ret;
    }
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    vector<int> v;
    v.assign(n, 0);
    for(auto &it: v) cin >> it;
    ll ret = solve(v, 1, v[0]);
    cout << ret << "\n";
}