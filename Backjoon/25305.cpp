#include <bits/stdc++.h>
using namespace std;
int N, K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    vector<int> V(N);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end(), greater<int>());
    cout << V[K-1] << "\n";
}