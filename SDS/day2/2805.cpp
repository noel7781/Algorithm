#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;
vector<ll> heights;

bool check(ll thr) {
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += max(heights[i] - thr, (ll)0);        
    }
    if(sum >= (ll)m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    heights.assign(n, 0);
    for(auto &it: heights) {
        cin >> it;
    }
    ll lo = 0, hi = 2*1e9;
    while(lo+1 < hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << "\n";
}