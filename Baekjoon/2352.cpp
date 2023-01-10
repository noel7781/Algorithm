#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int solve() {
    int ret = 0;
    vector<int> tmp;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(tmp.begin(), tmp.end(), v[i]); 
        if(it == tmp.end()) {
            tmp.push_back(v[i]);
        } else {
            *it = v[i];
        }
    }
    ret = tmp.size();
    return ret;
}

int main() {
    cin >> n;
    v.assign(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    cout << solve() << "\n";
}
