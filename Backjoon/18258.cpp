#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<int> q;
    int t; cin >> t;
    while(t--) {
        string cmd; int k;
        cin >> cmd;
        if(cmd == "push") {
            cin >> k;
            q.push_back(k);
        } else if(cmd == "front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        } else if(cmd == "back") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        } else if(cmd == "pop") {
            if(q.empty()) cout << -1 << "\n";
            else {
                int pr = q.front();
                q.pop_front();
                cout << pr << "\n";
            }
        } else if(cmd == "empty") {
            cout << q.empty() << "\n";
        } else {
            cout << q.size() << "\n";
        }
    }
}
