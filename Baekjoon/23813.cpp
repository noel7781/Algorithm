#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll ans = 0;
    string str; cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++) {
        ans += stoll(str);
        char c = str.back();
        str.pop_back();
        str = c + str;
    }
    cout << ans;
}