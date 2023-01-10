#include <bits/stdc++.h>
using namespace std;
string org, tar;
int solve(string s) {
    if(s == org) {
        return 1;
    }
    if(s.length() == org.length()) {
        return 0;
    }
    char front = s.front(), back = s.back();
    if(front == 'B' && back == 'B') {
        string sb = s.substr(1);
        reverse(sb.begin(), sb.end());
        return solve(sb);
    } else if(front == 'B' && back == 'A') {
        string sb = s.substr(1);
        reverse(sb.begin(), sb.end());
        return solve(sb) | solve(s.substr(0, s.length()-1));
    } else if(back == 'A') {
        return solve(s.substr(0, s.length()-1));
    } else {
        return 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> org >> tar;
    cout << solve(tar) << "\n";
}