#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int n, k, s;

int distance(int pos) {
    return abs(pos - s);
}

int solve(map<int, int>& s_m, map<int, int>& l_m) {
    int ret = 0;
    int carry = 0;
    int pos = 0;
    for(auto it = s_m.begin(); it != s_m.end();) {
        if(carry == k) {
            ret += distance(pos);
            carry = 0;
        }
        if(carry == 0) {
            pos = it->first;
        }
        if(carry+it->second > k) {
            it->second -= (k - carry);
            carry = k;
        } else {
            carry += it->second;
            it->second = 0;
            it++;
        }
    }
    if(!s_m.empty()) ret += distance(pos);
    carry = 0;
    pos = 0;
    for(auto it = l_m.rbegin(); it != l_m.rend();) {
        if(carry == k) {
            ret += distance(pos);
            carry = 0;
        }
        if(carry == 0) {
            pos = it->first;
        }
        if(carry+it->second > k) {
            it->second -= (k - carry);
            carry = k;
        } else {
            carry += it->second;
            it->second = 0;
            it++;
        }
    }
    if(!l_m.empty()) ret += distance(pos);
    return ret*2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    map<int, int> s_m;
    map<int, int> l_m;
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if(a > s) l_m[a] = b;
        else s_m[a] = b;
    }
    cout << solve(s_m, l_m) << "\n";
}
