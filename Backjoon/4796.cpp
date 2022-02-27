#include <bits/stdc++.h>
using namespace std;
int main() {
    int L, P, V;
    int t = 0;
    while(cin >> L >> P >> V) {
        t+=1;
        if(L == 0 && P == 0 && V == 0) break;
        int d = V / P;
        cout << "Case " << t << ": " << d * L + min(V % P, L) << "\n";
    }
    return 0;
}