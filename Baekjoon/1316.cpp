#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int last[26];

bool solve(string& str) {
    for(int i = 0; i < str.size(); ++i) {
        int alphabet = str[i] - 'a';
        if(last[alphabet] == -1) last[alphabet] = i;
        else {
            if(last[alphabet] == i-1) {
                last[alphabet] = i;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    int ret = 0;
    while(t--) {
        memset(last, -1, sizeof(last));
        string str; cin >> str;
        if(solve(str)) ret += 1;
    }
    cout << ret << "\n";
}
