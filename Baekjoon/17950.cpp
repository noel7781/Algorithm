#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll total = 0;
    vector<ll> v;
    int H, x; cin >> H >> x;
    while(H--) {
        ll s; cin >> s;
        v.push_back(s);
    }
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        total += *it;
        total %= MOD;
        total *= x;
        total %= MOD;
    }
    cout << total << "\n";
}