#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    stringstream ss(str);
    int ans = 0;
    while(getline(ss, str, ',')) {
        ans++;
    }
    cout << ans;
}