#include <bits/stdc++.h>
using namespace std;
bool isNumber(char c) {
    return '0' <= c and c <= '9';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    string str; cin >> str;
    int len = str.size();
    for(int i = 0; len; i++) {
        if(i < len-1) {

        } else {
            if(isNumber(str[i])) {
                ans++;
            }
        }
    }
}