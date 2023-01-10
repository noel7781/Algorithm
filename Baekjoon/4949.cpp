#include <iostream>
#include <stack>

using namespace std;

void solve(string str) {
    stack<char> s;
    for(auto it: str) {
        if(it == '(' || it == '[') {
            s.push(it);
        }
        if(it == ')') {
            if(!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                cout << "no\n";
                return;
            }
        } else if(it == ']') {
            if(!s.empty() && s.top() == '[') {
                s.pop();
            } else {
                cout << "no\n";
                return;
            }
        }
    }
    if(s.empty())
        cout << "yes\n";
    else
        cout << "no\n";
    return;
}

int main() {
    string str = "";
    while(1) {
        getline(cin, str);
        if(str == ".") break;
        solve(str);
    }
    return 0;
}