#include <bits/stdc++.h>

using namespace std;

int dp[2501];
int palen[2501][2501];

int isPalindrome(int i, int j, string& str) {
    if(i >= j) return 1;
    int& ret = palen[i][j];
    if(ret != -1) return ret;
    ret = 1;
    if(str[i] == str[j]) ret &= isPalindrome(i+1, j-1, str);
    else  ret = 0;
    return ret;
}

int solve(int i, string& str) {
    if(i == str.length()) return 0;
    int& ret = dp[i];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int k = i; k < str.length(); k++) {
        if(isPalindrome(i, k, str)) ret = min(ret, 1+solve(k+1, str));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(palen, -1, sizeof(palen));
    string str; cin >> str;
    cout << solve(0, str) << "\n";
}