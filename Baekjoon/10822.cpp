#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll ans = 0;
    string s; cin >> s;
    string token;
    stringstream ss(s);
    while(getline(ss, token, ',')) {
        ans += stoll(token);
    }
    cout << ans << "\n";
}
