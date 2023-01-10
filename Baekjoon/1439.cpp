#include <bits/stdc++.h>
using namespace std;
int main() {
    string str; cin >> str;
    int ones = 0, zeros = 0;
    if(str[0] == '0') zeros++;
    else ones++;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] != str[i-1]) {
            if(str[i] == '0') zeros++;
            else ones++;
        }
    }
    cout << min(zeros, ones) << "\n";
}