#include <bits/stdc++.h>

using namespace std;
int ms[] = { 300, 60, 10 };
int main() {
    int N; cin >> N;
    vector<int> ret;
    for(int i = 0; i < 3; i++) {
        ret.push_back(N/ms[i]);
        N %= ms[i];
    }
    if(N == 0) {
        for(auto it: ret) cout << it << " ";
    } else {
        cout << -1;
    }
    cout << "\n";
}