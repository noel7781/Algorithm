#include <bits/stdc++.h>
using namespace std;
int K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> K;
        multiset<int> s;
        for(int i = 0; i < K; i++) {
            char cmd; int num; cin >> cmd >> num;
            if(cmd == 'I') {
                s.insert(num);
            } else {
                if(s.empty()) continue;
                if(num == -1) {
                    s.erase(s.begin());
                } else {
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
            }
        }
        if(s.empty()) {
            cout << "EMPTY\n";
        } else {
            int p = *s.begin();
            int q = *(--s.end());
            cout << q << " " << p << "\n";
        }
    }
}