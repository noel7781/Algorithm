#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        set<int> s;
        int N; cin >> N;
        for(int i = 0; i < N; i++) {
            int x; cin >> x; s.insert(x);
        }
        cin >> N;
        for(int i = 0; i < N; i++) {
            int x; cin >> x;
            if(s.find(x) != s.end()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    
}