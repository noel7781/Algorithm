#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int x; cin >> x;
        x = max(x, 40);
        sum += x;
    }
    cout << sum / 5 << "\n";
}
