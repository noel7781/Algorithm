#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    unordered_set<string> us;
    int sz = str.size();
    for(int i = 0; i < sz; i++) for(int j = i; j < sz; j++) us.insert(str.substr(i, j-i+1));
    cout << us.size() << "\n";
}