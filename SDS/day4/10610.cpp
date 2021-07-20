#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;    
    sort(s.begin(), s.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }
    if(s.back() != '0' || sum % 3 != 0) {
        cout << -1 << "\n";
        return 0;
    } else {
        cout << s << "\n";
        return 0;
    }
}