#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        if(i == 0) v.push_back(num);
        else {
            int sz = v.size();
            for(int j = 0; j < sz; ++j) {
                v.push_back(abs(num-v[j]));
            }
            v.push_back(num);
            for(int j = 0; j < sz; ++j) {
                v.push_back(num+v[j]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(find(v.begin(), v.end(), t) != v.end()) cout << "Y\n";
        else cout << "N\n";
    }
}
