#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll limit = (ll)1e10;
int ret_l = 0, ret_m = (n-1)/2, ret_r = n-1;
map<tuple<int, int, int>, bool > mm;
bool done = false;


ll getSum(vector<ll>& v, int l, int m, int r) {
    return v[l] + v[m] + v[r];
}

void solve(vector<ll>& v, int l, int m, int r, bool start) {
    if(l >= m || m >= r) return;
    if(done) return;
    if(mm[make_tuple(l, m, r)] == true)
        return;
    mm[make_tuple(l, m, r)] = true;
    ll sum = 1e10;
    if(abs(v[l] + v[m] + v[r]) < limit) {
        limit = abs(v[l] + v[m] + v[r]);
        ret_l = l;
        ret_m = m;
        ret_r = r;
    }
    if(v[l] + v[m] + v[r] < 0) {
        solve(v, l+1, m, r, 0);
        solve(v, l, m+1, r, 0);
    } else if(v[l] + v[m] + v[r] == 0) {
        done = true;
        ret_l = l;
        ret_m = m;
        ret_r = r;
        return;
    } else {
        solve(v, l, m-1, r, 0);
        solve(v, l, m, r-1, 0);
    }
    if(start)
        cout << v[ret_l] << " " << v[ret_m] << " " << v[ret_r] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(v, 0, (n-1)/2 ,n-1, 1);
}
