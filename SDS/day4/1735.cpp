#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(a==b || b==0) return a;
    else return gcd(a % b, b);
}

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int up = a*d + b*c;
    int dn = b*d;
    int g = gcd(up, dn);
    cout << up / g << " " << dn / g << "\n";
}