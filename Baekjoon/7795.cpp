#include <bits/stdc++.h>
using namespace std;
int N, M;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> N >> M;
        vector<int> A(N), B(M);
        for(auto &it: A) cin >> it;
        for(auto &it: B) cin >> it;
        sort(B.begin(), B.end());
        int ret = 0;
        for(auto& num: A) {
            ret += lower_bound(B.begin(), B.end(), num) - B.begin();
        }
        cout << ret << "\n";
    }
}