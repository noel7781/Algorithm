#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(int data, vector<string>& instr) {
    stack<int> s;
    s.push(data);
    for(int i = 0; i < instr.size(); ++i) {
        if(instr[i] == "NUM") {
            i++;
            s.push(stoi(instr[i]));
        } else if(instr[i] == "POP") {
            if(s.empty()) {
                cout << "ERROR\n";
                return;
            } else {
                s.pop();
            }
        } else if(instr[i] == "INV") {
            if(s.empty()) {
                cout << "ERROR\n";
                return;
            } else {
                int back = s.top();
                s.pop();
                s.push(-back);
            }
        } else if(instr[i] == "DUP") {
            if(s.empty()) {
                cout << "ERROR\n";
                return;
            } else {
                int back = s.top();
                s.push(back);
            }
        } else if(instr[i] == "SWP") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                s.pop();
                s.push(back1);
                s.push(back2);
            }
        } else if(instr[i] == "ADD") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                s.pop();
                long long t = (long long)back1 + (long long)back2;
                if(t < -1e9 || t > 1e9) {
                    cout << "ERROR\n";
                    return;
                }
                s.push(back1+back2);
            }
        } else if(instr[i] == "SUB") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                s.pop();
                long long t = (long long)back2 - (long long)back1;
                if(t < -1e9 || t > 1e9) {
                    cout << "ERROR\n";
                    return;
                }
                s.push(back2-back1);
            }
        } else if(instr[i] == "MUL") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                s.pop();
                long long t = (long long)back1 * (long long)back2;
                if(t < -1e9 || t > 1e9) {
                    cout << "ERROR\n";
                    return;
                }
                s.push(back1*back2);
            }
        } else if(instr[i] == "DIV") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                if(back1 == 0) {
                    cout << "ERROR\n";
                    return;
                }
                s.pop();
                s.push(back2/back1);
            }
        } else if(instr[i] == "MOD") {
            if(s.empty() || s.size() == 1) {
                cout << "ERROR\n";
                return;
            } else {
                int back1 = s.top();
                s.pop();
                int back2 = s.top();
                s.pop();
                if(back1 == 0) {
                    cout << "ERROR\n";
                    return;
                }
                s.push(back2%back1);
            }
        }
    }
    if(s.size() == 1) {
        cout << s.top() << "\n";
    } else {
        cout << "ERROR\n";
    }
    return;
}

int main() {
    bool done = false;
    while(!done) {
        vector<string> instr;
        int data;
        string ins;
        int count = 0;
        while(true) {
            cin >> ins;
            if(ins == "END") {
                break;
            } else if(ins == "QUIT") {
                break;
            } else {
                instr.push_back(ins);
            }
        }
        if(ins == "QUIT") {
            break;
        }
        cin >> count;
        for(int i = 0; i < count; ++i) {
            cin >> data;
            solve(data, instr);
        }
        cout << "\n";

    }
}
