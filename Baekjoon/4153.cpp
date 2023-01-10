#include <ios>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(c*c == a*a + b*b) cout << "right\n";
        else cout << "wrong\n";
    }
}
