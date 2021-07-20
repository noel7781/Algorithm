#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solve(vector<ll>& v, int left, int right) {
    if(left == right) return v[left];
    int mid = (left + right) / 2;
    ll left_max = solve(v, left, mid);
    ll right_max = solve(v, mid+1, right);
    ll middle_max = 0;
    ll height = 1e9;
    int lo = mid, hi = mid+1;
    int dist = 0;
    ll l = -1, r = -1;
    while(lo >= left || hi <= right) {
        if(hi <= right) r = v[hi];
        else r = 0;
        if(lo >= left) l = v[lo];
        else l = 0;
        if(r == 0 && l == 0) break;
        dist += 1;
        if(l <= r) {
            height = min(height, r);
            middle_max = max(middle_max, height * dist);
            hi += 1;
        } else {
            height = min(height, l);
            middle_max = max(middle_max, height * dist);
            lo -= 1;
        }
    }
    return max(middle_max, max(left_max, right_max));
}

int main() {
    int size = 0;
    while(1) {
        cin >> size;
        if(size == 0) break;
        vector<ll> v(size);
        for(int i = 0; i < size; ++i) {
            cin >> v[i];
        }
        cout << solve(v, 0, size-1) << "\n";
    }
}