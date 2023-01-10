#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> V(N+M);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    for(auto it: V) cout << it << " ";
}