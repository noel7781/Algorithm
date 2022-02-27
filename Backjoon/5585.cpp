#include <bits/stdc++.h>

using namespace std;
int ms[] = { 500, 100, 50, 10, 5, 1 };
int main() {
    int N; cin >> N;
    N = 1000 - N;
    int ans = 0;
    for(int i = 0; i < 6; i++) {
        ans += N / ms[i];
        N %= ms[i];
    }
    cout << ans << "\n";
}