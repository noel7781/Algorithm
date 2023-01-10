#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    vector<string> v(t); for(auto &a: v) cin >> a;
    set<int> s;
    for(int i = 0; i < t; ++i) {
        for(int j = i+1; j < t; ++j) {
            for(int k = 0; k < v[i].size(); ++k) {
                if(v[i][k] != v[j][k]) s.insert(k);
            }
        }
    }
    string ret = v[0];
    for(auto a: s) {
        ret[a] = '?';
    }
    cout << ret << "\n";
}
