#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int ret = 0;
    for(int i = 0; i < 8; ++i) {
        string str; cin >> str;
        if(!(i % 2)) {
            for(int j = 0; j < 8; j += 2) {
                if(str[j]=='F') ret++;
            }
        } else {
            for(int j = 1; j < 8; j += 2) {
                if(str[j]=='F') ret++;
            }
        }
    }
    cout << ret << "\n";
}
