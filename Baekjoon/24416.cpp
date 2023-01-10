#include <bits/stdc++.h>
using namespace std;
int N;
int dp[41];

int fib(int n) {
    if(n == 1 || n == 2) return 1;
    int& ret = dp[n];
    if(ret != -1) return ret;
    return ret = fib(n-1) + fib(n-2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    
    cout << fib(N) << " " << N-2 << "\n";
}