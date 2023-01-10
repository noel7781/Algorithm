#include <bits/stdc++.h>
using namespace std;
string S, T;
int solve(string t, string& s) {
    if(t == s) return 1;
    if(t.length() == s.length()) return 0;
    char f = t.front(), e = t.back();
    t.pop_back();
    if(e == 'B') {
        reverse(t.begin(), t.end());
        return solve(t, s);
    } else {
        return solve(t, s);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S >> T;
    cout << solve(T, S) << "\n";
}