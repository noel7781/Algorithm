#include <bits/stdc++.h>
using namespace std;
int cnts[26];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    string ans = "";
    for(auto c: str) cnts[c-'A']++;
    int odd_cnts = 0;
    for(int i = 0; i < 26; i++) {
        if(cnts[i] % 2 == 1) {
            odd_cnts++;
            char c = i + 'A';
            ans += c;
            cnts[i]--;
        }
    }
    if(odd_cnts > 1) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    for(int i = 25; i >= 0; i--) {
        while(cnts[i]) {
            ans = char('A'+i) + ans;
            ans = ans + char('A'+i);
            cnts[i] -= 2;
        }
    }
    cout << ans << "\n";
}