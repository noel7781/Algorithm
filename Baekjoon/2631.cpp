#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int solve() {
    vector<int> v;
    for(int i = 0; i < N; i++) {
        auto it = lower_bound(v.begin(), v.end(), V[i]);
        if(it == v.end()) v.push_back(V[i]);
        else *it = V[i];
    }
    return v.size();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N);
    for(auto& it: V) cin >> it;
    int ret = solve();
    cout << N - ret << "\n";
}