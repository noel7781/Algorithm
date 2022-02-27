#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V(8);
    for(auto &it: V) cin >> it;
    if(is_sorted(V.begin(), V.end())) {
        cout << "ascending" << "\n";
    } else if(is_sorted(V.rbegin(), V.rend())) {
        cout << "descending" << "\n";
    } else {
        cout << "mixed" << "\n";
    }
    return 0;
}