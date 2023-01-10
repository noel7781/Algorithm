#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n; vector<int> v(n);
        for(auto &it: v) cin >> it;
        int ans = -1e9;
        int sum = 0;
        for(auto x: v) {
            sum += x;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        cout << ans << "\n";
    }
}