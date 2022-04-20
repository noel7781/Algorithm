#include <bits/stdc++.h>
using namespace std;
string str;

int counts[26][200002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for(int i = 0; i < (int)str.size(); i++) {
        if(i == 0) counts[str[i]-'a'][i] = 1;
        else {
            for(int j = 0; j < 26; j++) {
                counts[j][i] = counts[j][i-1];
            }
            counts[str[i]-'a'][i] = counts[str[i]-'a'][i-1]+1;
        }
    }
    int q; cin >> q;
    while(q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        cout << counts[c-'a'][r] - (l > 0 ? counts[c-'a'][l-1] : 0) << "\n";
    }
}