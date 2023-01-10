#include <bits/stdc++.h>
using namespace std;
string translate(char& c) {
    int n = c - '0';
    string ret = "";
    for(int i = 0; i < 3; i++) {
        if(n & (1 << (2-i))) ret += "1";
        else ret += "0";
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    if(str == "0") {
        cout << 0 << "\n";
        return 0;
    }
    string tmp;
    bool is_start = false;
    for(int i = 0; i < str.size(); i++) {
        tmp = translate(str[i]);
        if(str[i] != '0') {
            if(!is_start) {
                cout << stoi(tmp);
            } else {
                cout << tmp;
            }
            is_start = true;
        } else {
            if(is_start) cout << tmp;
            else continue;
        }
    }
    cout << "\n";
    return 0;
}