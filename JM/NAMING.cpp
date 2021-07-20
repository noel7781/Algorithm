#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> getPartial(const string& s) {
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

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    s1 += s2;
    vector<int> pi = getPartial(s1);
    vector<int> ret;
    int n = s1.size();
    while(n > 0) {
        ret.push_back(n);
        n = pi[n-1];
    }
    for(auto it = ret.rbegin(); it != ret.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

}
