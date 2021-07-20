#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string s1;

vector<int> getPartialMatch(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    int begin = 1, matched = 0;
    while(begin + matched < n) {
        if(s[begin + matched] == s[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if(matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int solve(const string& a, const string& b) {
    int n = a.size();
    int begin = 0, matched = 0;
    vector<int> pi = getPartialMatch(b);
    while(begin < n) {
        if(matched < n && a[begin + matched] == b[matched]) {
            ++matched;
            if(begin + matched == n)
                return matched;
        } else {
            if(matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> s1;
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        int ret = solve(s1, s2);
        cout << 2*n - ret  <<"\n";
    }
}
