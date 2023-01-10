#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string N; int B; cin >> N >> B;
    reverse(N.begin(), N.end());
    int ans = 0;
    int acc = 1;
    for(int i = 0; i < (int)N.size(); i++) {
        if('A' <= N[i] && N[i] <= 'Z') {
            ans += (N[i] - 'A' + 10) * acc;
        } else {
            ans += (N[i] - '0') * acc;
        }
        acc *= B;
    }
    cout << ans << "\n";
}