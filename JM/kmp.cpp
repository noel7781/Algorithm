#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> getPartialMatch(const String& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if(N[begin + matched] == N[matched]) {
            ++matched;
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
vector<int> kmpSearch(const string& H, const String& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
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
	string a,b;
	cout << "Write down Two Strings\n";
	cin >> a >> b;
	vector<int> res = kmpSerach(a,b);
	for(int i = 0; i < res.size(); ++i) {
		cout << res[i] << "\t";
	}
    return 0;
}

