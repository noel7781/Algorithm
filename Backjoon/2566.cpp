#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int mx = -1, my = -1, m = -1;
    int k;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cin >> k;
            if(k > m) {
                m = k; my = i; mx = j;
            }
        }
    }
    cout << m << "\n";
    cout << my << " " << mx << "\n";
}