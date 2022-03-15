#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull n; cin >> n;
    ull lo = -1, hi = (1ULL << 32) - 1;
    while(lo+1 < hi) {
        ull mid = lo+hi>>1;
        if(mid*mid >= n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}