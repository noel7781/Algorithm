#include <iostream>
#include <cstring>

using namespace std;

string n;
int cnt = 0;

int solve(string next) {
    if(stoi(n) == stoi(next) && cnt != 0) return 0;
    cnt = 1;
    int ret = 0;
    int next_int = stoi(next);
    string next_str = "";
    if(next_int >= 10) {
        string add = to_string((next[0] -'0' + next[1] -'0') % 10);
        next_str = next.back() + add;
    } else {
        string add = to_string(next_int);
        next_str = next.back() + add;
    }
    ret = 1 + solve(next_str);
    return ret;
}

int main() {
    cin >> n;
    int ret = solve(n);
    cout << ret << "\n";
}
