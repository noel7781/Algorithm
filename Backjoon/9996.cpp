#include <bits/stdc++.h>
using namespace std;
string pattern;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    cin >> pattern;
    int asterisk_points = pattern.find('*');
    while(t--) {
        string s; cin >> s;
        if(s.substr(0, asterisk_points) == pattern.substr(0, asterisk_points)) {
            int len = pattern.size() - asterisk_points - 1;
            if(s.size() >= pattern.size()-1 && s.substr(s.size() - len) == pattern.substr(asterisk_points+1)) {
                cout << "DA\n";
            } else {
                cout << "NE\n";
            }
        } else {
            cout << "NE\n";
        }
    }
}