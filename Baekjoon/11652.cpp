#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<ll, int> m;
    cin >> N;
    ll min_val = LLONG_MAX;
    int max_cnt = 0;

    for(int i = 0; i < N; i++) {
        ll x; cin >> x;
        m[x]++;
        if(m[x] > max_cnt) {
            max_cnt = m[x];
            min_val = x;
        } else if(m[x] == max_cnt) {
            min_val = min(min_val, x);
        }
    }
    cout << min_val << "\n";
    return 0;
}