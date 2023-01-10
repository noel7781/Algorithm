#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int r = 31;
const int M = 1234567891;
int main() {
    int L; cin >> L;
    ll ret = 0;
    string str; cin >> str;
    ll pow = 1;
    for(int i = 0; i < L; i++) {
        ret += ((str[i] - 'a' + 1) * pow) % M;
        ret %= M;
        pow *= r;
        pow %= M;
    }
    cout << ret << "\n";
}