#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int N; cin >> N;
        vector<int> v(N); for(auto &it: v) cin >> it;
        ll ret = 0;
        for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++) ret += gcd(v[i], v[j]);
        cout << ret << "\n";
    }
}