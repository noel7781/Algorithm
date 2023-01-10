#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str; cin >> str;
    stack<char> s;
    bool fail = false;
    int ret = 0;
    int tmp = 1;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') {
            s.push(str[i]);
            tmp *= 2;
        } else if(str[i] == '[') {
            s.push(str[i]);
            tmp *= 3;
        } else {
            if(s.empty()) {
                fail = true;
                break;
            } else if(str[i] == ')') {
                if(s.top() == '(') {
                    if(str[i-1] == '(') ret += tmp;
                    s.pop();
                    tmp /= 2;
                } else {
                    fail = true;
                    break;
                }
            } else if(str[i] == ']') {
                if(s.top() == '[') {
                    if(str[i-1] == '[') ret += tmp;
                    s.pop();
                    tmp /= 3;
                } else {
                    fail = true;
                    break;
                }
            }
        }
    }
    if(!fail && s.empty()) {
        cout << ret << "\n";
    } else {
        cout << 0 << "\n";
    }
}
