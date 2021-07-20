#include <iostream>

using namespace std;

typedef long long ll;

ll n; 

bool decision(ll mid) {
    if((mid*(mid+1)) / 2 >= n) return true;
    return false;
}

int main() {
    cin >> n;
    ll lo = 0, hi =10000000;
    ll mid = (lo + hi) / 2;
    ll ret = 0;
    while(lo + 1 < hi) {
        mid = (lo + hi) / 2;
        if(decision(mid)) {
            ret = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    ll before = ret;
    ll after = 1;
    ll diff = ((ret)*(ret+1))/2 - n;
    before -= diff;
    after += diff;
    if(ret % 2) {
        swap(before, after);
    }
    cout << before << "/" << after << "\n";
}
