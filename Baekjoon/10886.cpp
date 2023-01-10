#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, L = 0, D = 0;
    cin >> T;
    for(int i = 0; i < T; i++ ){
        int x; cin >> x;
        if(x) L++;
        else D++;
    }
    if(D > L) cout << "Junhee is not cute!";
    else cout << "Junhee is cute!";
}