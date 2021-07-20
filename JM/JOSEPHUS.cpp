#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, k;

void solve() {
    list<int> l;
    for(int i = 1; i <= n; ++i) {
        l.push_back(i);
    }
    auto it = l.begin();
    while(l.size() > 2) {
        it = l.erase(it); if(it == l.end()) it = l.begin();
        for(int s = 1; s < k; ++s) {
            it++; if(it == l.end()) it = l.begin();
        }
    }
    for(auto x: l) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }
}
