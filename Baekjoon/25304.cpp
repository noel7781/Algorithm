#include <bits/stdc++.h>
using namespace std;
int X;
int N;
int a, b;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> X >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        X -= a*b;
    }
    cout << (X == 0 ? "Yes\n" : "No\n");
    return 0;
}