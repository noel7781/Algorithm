#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    string n1, n2; cin >> n1 >> n2;
    if(n1.size() < n2.size()) swap(n1, n2);
    int n1Len = n1.size();
    int n2Len = n2.size();
    int adder = 0;
    string ret = "";
    for(int i = 0; i < n2Len; ++i) {
        int tmp = n1.back() - '0' + n2.back() - '0' + adder;
        if(tmp >= 10) {
            adder = 1;
            tmp %= 10;
        } else {
            adder = 0;
        }
        ret += to_string(tmp);
        n1.pop_back();
        n2.pop_back();
    }
    for(int i = 0; i < n1Len - n2Len; ++i) {
        int tmp = n1.back() - '0' + adder;
        if(tmp >= 10) {
            adder = 1;
            tmp %= 10;
        } else {
            adder = 0;
        }
        ret += to_string(tmp);
        n1.pop_back();
    }
    if(adder == 1) {
        ret += '1';
    }
    reverse(ret.begin(), ret.end());
    cout << ret << "\n";

}
