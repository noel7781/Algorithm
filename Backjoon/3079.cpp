#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int N; ll M;
vector<ll> V;
int main() {
    cin >> N >> M;
    V.resize(N);
    for(auto &it: V) cin >> it;
    ll lo = 0, hi = *max_element(V.begin(), V.end()) * M;
    while(lo+1 < hi) {
        ll mid = (lo+hi)/2;
        ll sum = 0;
        for(int i = 0; i < N; i++) {
            sum += (mid / V[i]);
        }
        if(sum >= M) hi = mid;
        else lo = mid;
    }
    cout << hi << "\n";
}