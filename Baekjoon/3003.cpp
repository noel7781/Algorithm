#include <bits/stdc++.h>
using namespace std;
int tar[] = {1, 1, 2, 2, 2, 8};
int main() {
    int len = 6;
    for(int i = 0; i < len; i++) {
        int x; cin >> x;
        cout << tar[i] - x << " ";
    }
    cout << "\n";
    return 0;
}