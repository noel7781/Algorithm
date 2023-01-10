#include <bits/stdc++.h>
using namespace std;
string ppap = "PAPP";
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    stack<char> s;
    int len = str.size();
    bool check_time = false;
    bool is_ppap = true;
    for(int i = 0; i < len; i++) {
        if(!is_ppap) break;
        if(!s.empty() && s.top() == 'A') {
            check_time = true;
        }
        s.push(str[i]);
        if(check_time) {
            for(int j = 0; j < 4; j++) {
                if(s.empty()) {
                    is_ppap = false;
                    break;
                }
                char c = s.top(); s.pop();
                if(c != ppap[j]) {
                    is_ppap = false;
                    break;
                }
            }
            if(is_ppap) s.push('P');
            check_time = false;
        }
    }
    if(s.size() == 1 && s.top() == 'P') {
        cout << "PPAP\n";
    } else {
        cout << "NP\n";
    }
    return 0;
}