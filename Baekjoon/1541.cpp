#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> v;
    vector<char> op;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '+' || str[i] == '-') {
            op.push_back(str[i]);
            continue;
        }
        int start = i;
        while(!(str[start] == '+' || str[start] == '-')) {
            start++;
        }
        string st = str.substr(i, start - i);
        i = start-1;
        v.push_back(stoi(st));
    }
    int op_cnt = op.size();
    int ret = 0;
    auto it = v.begin();
    for(int i = 0; i < op.size(); ++i) {
        if(op[i] == '+') {
            int sum = *it + *(it+1);
            it = v.erase(it);
            *it = sum;
        } else {
            it++;
        }
    }
    ret = v[0];
    for(int i = 1; i < v.size(); ++i) {
        ret -= v[i];
    }
    cout << ret << "\n";
}