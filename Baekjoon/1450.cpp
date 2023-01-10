#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll c;

void calc_sum(vector<ll>& weights, vector<ll>& save, int start, int end, ll sum) {
    if(start == end) {
        if(sum <= c)
            save.push_back(sum);
        return;
    }
    calc_sum(weights, save, start+1, end, sum);
    calc_sum(weights, save, start+1, end, sum+weights[start]);
    return;
}

ll solve(vector<ll>& weights) {
    ll ret = 0;
    vector<ll> left, right;
    calc_sum(weights, left, 0, n/2, 0);
    calc_sum(weights, right, n/2, n, 0);
    sort(right.begin(), right.end());
    for(int i = 0; i < left.size(); ++i) {
        ll ls = left[i];
        int l = 0, r = right.size() - 1;
        int mid = (l + r) / 2;
        int res = 0;
        while(l <= r) {
            mid = (l + r) / 2;
            if(ls + right[mid] > c) {
                r = mid - 1;
            } else if(ls + right[mid] <= c) {
                res = max(res, mid);
                l = mid + 1;
            }
        }
        res += 1;
        ret += (ll)res;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    vector<ll> weights(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    cout << solve(weights) << "\n";
}
