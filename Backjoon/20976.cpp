#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> V(3);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end()); cout << V[1] << "\n";
}