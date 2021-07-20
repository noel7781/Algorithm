#include <iostream>
#include <vector>
#include <cstring>

#define MOD 20091101

using namespace std;

int n, k;

int pSum[1000010];

void partialSum(vector<int>& v) {
    pSum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pSum[i] = v[i] + pSum[i-1];
        pSum[i] %= k;
    }
}

int solve_1() {
    int ret = 0;
    vector<long long> count(k, 0);
    for(int i = 0; i < n+1; ++i) {
        count[pSum[i]]++;
    }
    for(int i = 0; i < k; ++i) {
        if(count[i] >= 2)
            ret = (ret + ((count[i] * (count[i]-1)) / 2)) % MOD;
    }
    return ret;
}

int solve_2() {
    vector<int> ret(n+1, 0);
    vector<int> prev(k, -1);
    for(int i = 0; i < n+1;  ++i) {
        if(i > 0)
            ret[i] = ret[i-1];
        else
            ret[i] = 0;
        int loc = prev[pSum[i]];
        if(loc != -1) ret[i] = max(ret[i], ret[loc]+1);
        prev[pSum[i]] = i;
    }
    return ret.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(pSum, 0, sizeof(pSum));
        cin >> n >> k;
        vector<int> v(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        partialSum(v);
        cout << solve_1() << " ";
        cout << solve_2() << "\n";
    }
}
