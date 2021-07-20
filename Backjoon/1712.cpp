#include <iostream>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if(b >= c) {
        cout << -1 << "\n";
    } else {
        int ret = a / (c-b) + 1;
        cout << ret << "\n";
    }
}
