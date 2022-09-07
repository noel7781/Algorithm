#include <bits/stdc++.h>
using namespace std;
vector<int> s(3, 0);
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(auto &it: s) cin >> it;
    int T, ans = 0;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int tmp = 0;
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                int x; cin >> x;
                tmp += x * s[k];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}