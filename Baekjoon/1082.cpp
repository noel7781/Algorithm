#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> costs;
int m;
string cache[51];

bool comp(string& a, string& b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
    /* 왜 안되지 ? 
    if(a.length() != b.length()) {
        return (b.length() - a.length()) > 0;
    } else {
        return a < b;
    }
    */
}

string solve(int money) {
    string& ret = cache[money];
    if(ret != "") {
        return ret;
    }
    if(m == money) {
        string next = "";
        for(int i = 1; i < n; ++i) {
            if(money >= costs[i]) {
                next = to_string(i) + solve(money - costs[i]);
                if(comp(ret, next)) {
                    ret = next;
                }
            } else {
                continue;
            }
        }
        if(next == "") {
            return "";
        }
    } else {
        string next = "";
        for(int i = 0; i < n; ++i) {
            if(money >= costs[i]) {
                next = to_string(i) + solve(money - costs[i]);
                if(comp(ret, next)) {
                    ret = next;
                }
            } else {
                continue;
            }
        }
        if(next == "") {
            return "";
        }
    }
    return ret;
}

int main() {
    for(int i = 0; i < 51; ++i) {
        cache[i] = "";
    }
    cin >> n;
    costs.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    cin >> m;
    string ret = solve(m);
    if(ret == "") {
        ret = "0";
    }
    cout << ret << "\n";
}
