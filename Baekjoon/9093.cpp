#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        string str; getline(cin, str);
        string tmp;
        stringstream ss(str);
        while(ss >> tmp) {
            for(auto it = tmp.rbegin(); it != tmp.rend(); it++) {
                cout << *it;
            }
            cout << " ";
        }
        cout << "\n";
    }
}