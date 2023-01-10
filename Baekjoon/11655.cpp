#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    getline(cin, str);
    for(int i = 0; i < (int)str.size(); i++) {
        char c = str[i];
        if('A' <= c and c <= 'Z') {
            c -= 'A';
            c += 13;
            c %= 26;
            c += 'A';
        } else if('a' <= c and c <= 'z') {
            c -= 'a';
            c += 13;
            c %= 26;
            c += 'a';
        }
        cout << c;
    }
    cout << "\n";
    return 0;
}