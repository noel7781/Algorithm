#include <iostream>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0, begin = 1;
    while(begin + matched < m) {
        if(N[begin + matched] == N[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
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

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int matched = 0, begin = 0;
    while(begin <= n - m) {
        if(matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if(matched == m)
                ret.push_back(begin);
        }
        else {
            if(matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    string H, N;
    getline(cin, H);
    getline(cin, N);
    vector<int> ret;
    ret = kmpSearch(H, N);
    cout << ret.size() << "\n";
    for(int i = 0; i < ret.size(); ++i) {
        cout << ret[i] + 1 << "\n";
    }
    return 0;
}
