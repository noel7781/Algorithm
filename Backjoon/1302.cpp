#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--) {
        string str; cin >> str;
        m[str]++;
    }
    int max_cnt = 0;
    string ans = "";
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > max_cnt) {
            ans = it->first;
            max_cnt = it->second;
        } else if(it->second == max_cnt) {
            if(ans > it->first) ans = it->first;
        }
    }
    cout << ans << "\n";
    return 0;
}