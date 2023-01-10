#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

void solve(vector<ll> v) {
    int left = 0, right = n-1;
    int ret_l = 0, ret_r = n-1;
    ll sum = 1e10;
    while(left < right) {
        if(abs(v[left] + v[right]) < sum) {
            sum = abs(v[left] + v[right]);
            ret_l = left;
            ret_r = right;
        }
        if(v[left] + v[right] < 0) {
            left += 1;
        } else if(v[left] + v[right] == 0) {
            cout << v[ret_l] << " " << v[ret_r] << endl;
            return;
        } else {
            right -= 1;
        }
    }
    cout << v[ret_l] << " " << v[ret_r] << endl;
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
    solve(v);
}
