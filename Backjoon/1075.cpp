#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b; cin >> a >> b;
    int ans = 0;
    a -= (a % 100);
    for(int i = 0; i < 100; i++) {
        int tmp = a + i;
        if(tmp % b == 0) {
            ans = i;
            break;
        }
    }
    cout << (ans < 10 ? "0" : "") << ans << "\n";
    
}