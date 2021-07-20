#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> v;

int solve() {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        cout << solve() << "\n";
    }
}
