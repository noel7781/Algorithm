#include <iostream>

using namespace std;

typedef long long ll;

ll n; 

bool decision(ll mid) {
    if(3*mid*mid - 3*mid + 1 >= n) return true;
    return false;
}

int main() {
    cin >> n;
    ll lo = 0, hi = 1000000000;
    ll mid = (lo + hi) / 2;
    ll ret = 0;
    while(lo+1 < hi) {
        mid = (lo + hi) / 2;
        if(decision(mid)) {
            ret = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << ret << "\n";
}
