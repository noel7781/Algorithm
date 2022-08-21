#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    N %= 10;
    string str = "SciComLove";
    for(int j = N; j < 10; j++) {
        cout << str[j];
    }
    for(int j = 0; j < N; j++) {
        cout << str[j];
    }
}