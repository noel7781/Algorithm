#include <iostream>

using namespace std;

int main() {
    long long lo = 0, hi = 1e10;
    long long n;
    cin >> n;
    while(lo <= hi) {
        long long mid = (lo + hi) / 2;
        if((mid * (mid+1)) / 2 > n)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << hi << "\n";
}
