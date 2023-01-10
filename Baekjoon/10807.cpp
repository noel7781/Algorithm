#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    cin >> v;
    for(auto it: V) ans += (it == v);
    cout << ans;
}