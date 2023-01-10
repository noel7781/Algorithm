#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int ans = 0;
        cin >> A >> B >> C;
        for(int a = 1; a <= A; a++) for(int b = 1; b <= B; b++) for(int c = 1; c <= C; c++)
            if(a % b == b % c && b % c == c % a) ans++;

        cout << ans << "\n";
    }

}