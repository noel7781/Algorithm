#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
int dp[1000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    vector<int> nums(3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    dp[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        for(int num: nums) {
            if(i - num >= 0) {
                dp[i] += dp[i-num];
                dp[i] %= MOD;
            }
        }
    }
    while(t--){ 
        int x; cin >> x; cout << dp[x] << "\n";
    }
}