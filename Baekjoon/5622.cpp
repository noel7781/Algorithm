#include <iostream>
#include <cstring>

using namespace std;

int getTime(char c) {
    if('A' <= c && c <= 'C') return 2;
    else if(c <= 'F') return 3;
    else if(c <= 'I') return 4;
    else if(c <= 'L') return 5;
    else if(c <= 'O') return 6;
    else if(c <= 'S') return 7;
    else if(c <= 'V') return 8;
    else return 9;
}

int main() {
    string str; cin >> str;
    int ret = str.size();
    for(int i = 0; i < str.size(); ++i) {
        ret += getTime(str[i]);
    }
    cout << ret << "\n";
}
