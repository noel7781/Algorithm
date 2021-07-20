#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int house_cnt, n;
vector<ll> houses;

bool check(ll mid) {
    int cnt = 1;
    int start = 0;
    for(int i = 0; i < house_cnt; ++i) {
        if(houses[i] - houses[start] >= mid) {
            start = i;
            cnt += 1;
        }
    }
    if(cnt >= n)
        return true;
    return false;
}

ll solve() {
    ll ret = 0;
    ll lo = 0, hi = 1e12;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid))
            lo = mid+1;
        else
            hi = mid-1;
    }
    return (lo + hi) / 2;
}

int main() {
    cin >> house_cnt >> n;
    houses.assign(house_cnt, 0);
    for(int i = 0; i < house_cnt; ++i) {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
    cout << solve() << "\n";
}
