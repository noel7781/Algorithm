#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N; 
        vector<ll> V(N); for(auto &it: V) cin >> it;
        ll max_v = V.back();
        ll ans = 0;
        for(int i = (int)V.size() - 1; i >= 0; i--) {
            max_v = max(max_v, V[i]);
            ans += max(max_v - V[i], 0LL);
        }
        cout << ans << "\n";
    }
}