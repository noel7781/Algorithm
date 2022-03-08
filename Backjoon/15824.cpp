#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int N;
vector<ll> V;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    ll mul = 1;
    ll ret = 0;
    ll tmp = 0;
    for(int i = 0; i < N-1; i++) {
        mul *= 2;
        mul %= MOD;
        tmp = (V[i+1] - V[N-i-2]) % MOD;
        ret += (mul-1) * tmp;
        ret %= MOD;
    }
    cout << ret << "\n";
}
