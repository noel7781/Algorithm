#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N == 1) {
        cout << 0 << "\n";
        return 0;
    } 
    for(int j = 1; ; j += 2) {
        if(N <= j) {
            cout << j-N << "\n";
            return 0;
        }
        N -= j;
        if(N < j+1) {
            cout << 0 << "\n";
            return 0;
        }
        N -= (j+1);
    }
}