#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; vector<int> V;
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end(), greater<int>());
    for(auto it: V) cout << it << "\n";
}