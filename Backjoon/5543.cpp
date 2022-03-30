#include <bits/stdc++.h>
using namespace std;
int main() {
    int min_v=1e9;
    int ret = -50;
    for(int i = 0; i < 3; i++) {
        int x; cin >> x;
        min_v = min(min_v, x);
    }
    ret += min_v;
    min_v= 1e9;
    for(int i = 0; i < 2; i++) {
        int x; cin >> x;
        min_v = min(min_v, x);
    }
    ret += min_v;
    cout << ret << "\n";
}