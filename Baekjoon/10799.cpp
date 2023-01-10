#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    stack<char> s;
    int pipe_count = 0;
    int ret = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' && str[i+1] == ')') {
            ret += s.size();
            i++;
        } else if(str[i] == '(') {
            s.push('(');
            pipe_count++;
        } else if(str[i] == ')') {
            s.pop();
        }
    }
    cout << ret + pipe_count << "\n";
}