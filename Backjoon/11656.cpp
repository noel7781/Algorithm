#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    vector<string> v;
    for(int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i));
    }
    sort(v.begin(), v.end());
    for(auto it: v) cout << it << "\n";
}
