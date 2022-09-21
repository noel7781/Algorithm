#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; vector<int> V(N); for(auto &it: V) cin >> it;
    int ans = 0;
    int back = V.back();
    for(int i = N-1; i >= 0; i--) {
        if(V[i] >= back) ans += (V[i] - back);
        else back = V[i];
        back--;
    }
    cout << ans;
}