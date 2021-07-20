#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

string str;
int p_o, p_c, a_o, a_c;

int main() {
    cin >> str;
    stack<char> s;
    int ret = 0;
    int tmp = 1;
    for(int i = 0; i < str.size(); ++i) {
        char next = str[i];
        if(next == '(') p_o++;
        if(next == ')') p_c++;
        if(next == '[') a_o++;
        if(next == ']') a_c++;
        if(p_o < p_c || a_o < a_c) {
            cout << 0 << "\n";
            exit(0);
        }
    }
}