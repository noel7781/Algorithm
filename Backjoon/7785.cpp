#include <bits/stdc++.h>
using namespace std;
int N;
map<string, bool> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string name, status; cin >> name >> status;
        if(status == "enter") {
            m[name] = 1;
        } else {
            m[name] = 0;
        }
    }
    for(auto it = m.rbegin(); it != m.rend(); it++) {
        if(it->second) cout << it->first << "\n";
    }
}