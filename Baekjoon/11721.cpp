#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str; cin >> str;
    int size = str.size() / 10;
    for(int i = 0; i < size; ++i) {
        cout << str.substr(0, 10) << "\n";
        str = str.substr(10);
    }
    cout << str << "\n";
}