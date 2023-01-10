#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
vector<string> v;
int modular[16];
int l_mod[51];
int total = 0;
ll cache[(1 << 16)][101];

ll factorial(int n) {
    if(n == 1) return (ll)1;
    return factorial(n-1) * (ll)n;
}


ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a == b || b == 0) return a;
    return gcd(a % b, b);
}

int getModular(string& str) {
    int ret = 0;
    for(int i = 0; i < str.size(); ++i) {
        ret *= 10;
        ret += (str[i] - '0');
        ret %= k;
    }
    return ret;
}

ll generate(int taken, int mod) {
    if(taken == (1 << n) - 1) {
        return (mod == 0) ? (ll)1 : (ll)0;
    }
    ll& ret = cache[taken][mod];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; ++i) {
        if(taken & (1 << i)) continue;
        int nextTaken = taken | (1 << i);
        int nextMod = (mod*l_mod[v[i].length()] + modular[i]) % k;
        ret += generate(nextTaken, nextMod);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    memset(modular, 0, sizeof(modular));
    memset(l_mod, 0, sizeof(l_mod));
    cin >> n;
    v.assign(n, "");
    for(auto &it: v) cin >> it;
    cin >> k;
    for(int i = 0; i < n; ++i) {
        modular[i] = getModular(v[i]);
    }
    l_mod[0] = 1;
    for(int i = 1; i <= 50; ++i) {
        l_mod[i] = (l_mod[i-1] * 10) % k;
    }
    ll down = factorial(n);
    ll up = generate(0, 0);
    if(up == 0) {
        cout << "0/1\n";
    } else if(up == down) {
        cout << "1/1\n";
    } else {
        ll g = gcd(down, up);
        cout << up/g << "/" << down/g << "\n";
    }
}
