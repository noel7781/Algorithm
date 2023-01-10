#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    long long ret = 1;
    for(int i = 1; i <= N; i++) {
        ret *= i;
        while(ret % 10 == 0) ret /= 10;
        ret %= MOD;
    }
    cout << ret % 10 << "\n";
}