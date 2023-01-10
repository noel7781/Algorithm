#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> v;

int solve() {
    int ret = 0;
    vector<int> s;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(s.begin(), s.end(), v[i]);
        if(it == s.end()) {
            s.push_back(v[i]);
        } else {
            *it = v[i];
        }

    }
    return n-(int)s.size();
}

int main() {
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve() << "\n";
}
