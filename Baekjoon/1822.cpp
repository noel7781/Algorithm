#include <bits/stdc++.h>
using namespace std;
int A, B;
set<int> P, Q;
vector<int> ans;
int x;
int main() {
    cin >> A >> B;
    for(int i = 0; i < A; i++) {
        cin >> x; P.insert(x);
    }
    for(int i = 0; i < B; i++) {
        cin >> x; Q.insert(x);
    }
    for(auto it: P) {
        if(Q.find(it) == Q.end()) {
            ans.push_back(it);
        }
    }
    cout << ans.size() << "\n";
    for(auto it: ans) {
        cout << it << " ";
    }
}