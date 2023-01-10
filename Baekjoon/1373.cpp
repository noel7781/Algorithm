#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    if(str.size() % 3 == 1) {
        string tmp = "00";
        str = tmp + str;
    } else if(str.size() % 3 == 2) {
        string tmp = "0";
        str = tmp + str;
    }
    for(int i = 0; i < str.size(); i += 3) {
        string sub = str.substr(i, 3);
        int tmp = 0;
        for(int i = 0; i < 3; i++) {
            if(sub[i] == '1') {
                tmp |= (1 << (2-i));
            }
        }
        cout << tmp;
    }
    cout << "\n";
}