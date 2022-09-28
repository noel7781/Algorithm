#include <bits/stdc++.h>
using namespace std;
int N;
int ans = 0;
void solve(int sum, int pos) {
    if(pos == N) {
        if(sum == 0) ans++;
        return;
    }
    for(int i = 0; i < 3; i++) {
        solve((sum+i)%3, pos+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N == 1) {
        cout << 0;
    } else {
        solve(1, 1);
        solve(2, 1);
        cout << ans;
    }
}