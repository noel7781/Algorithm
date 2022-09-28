#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    int ans = 0;
    for(auto c: str) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') ans++;
    }
    cout << ans;
}