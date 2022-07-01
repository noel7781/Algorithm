#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    for(const auto& c: str) {
        cout << char(c ^ 32);
    }
    cout << "\n";
    return 0;
}