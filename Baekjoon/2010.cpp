#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        ans += x;
    }
    ans -= (N-1);
    cout << ans;
}