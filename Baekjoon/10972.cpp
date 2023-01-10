#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; v.resize(N);
    for(auto &it: v) cin >> it;
    if(next_permutation(v.begin(), v.end())) {
        for(auto it: v) cout << it << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}