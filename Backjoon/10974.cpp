#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) v[i] = i+1;
    do {
        for(auto it: v) cout << it << " ";
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}