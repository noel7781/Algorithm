#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<int> V(N);
        for(auto &it: V) cin >> it;
        sort(V.begin(), V.end());
        int f = V.front();
        int b = V.back();
        cout << (b-f)*2 << "\n";
    }
}