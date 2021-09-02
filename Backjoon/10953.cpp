#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        cout << str[0] - '0' + str[2] - '0' << "\n";
    }
}
