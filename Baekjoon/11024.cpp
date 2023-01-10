#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        int ans = 0;
        int x;
        while(ss >> x) {
            ans += x;
        }
        cout << ans << "\n";
    }
}