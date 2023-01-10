#include <bits/stdc++.h>
using namespace std;
int solve(string& str, int l, int r, int flag) {
    if(l >= r) {
        if(flag) return 1;
        return 0;
    }
    if(str[l] == str[r]) {
        return solve(str, l+1, r-1, flag);
    } else {
        if(flag) return 2;
        else {
            int ret = solve(str, l+1, r, 1);
            if(ret == 2) ret = solve(str, l, r-1, 1);
            return ret;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        string str; cin >> str;
        cout << solve(str, 0, (int)str.size()-1, 0) << "\n";
    }
}