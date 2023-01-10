#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str; cin >> str;
    string ret = "";
    ret += str[0];
    for(int i = 1; i < str.size(); ++i) {
        if(str[i] == '-') {
            ret += str[i+1];
        }
    }
    cout << ret << "\n";
}
