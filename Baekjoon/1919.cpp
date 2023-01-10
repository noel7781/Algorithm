#include <bits/stdc++.h>
using namespace std;
int c1[26];
int c2[26];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    for(auto c: str1) {
        c1[c-'a']++;
    }
    for(auto c: str2) {
        c2[c-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += abs(c1[i] - c2[i]);
    }
    cout << ans << "\n";
}