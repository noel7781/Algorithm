#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

ull pow(ull A, ull B, ull C) {
    if(B == 1)
        return A % C;
    ull ret = pow(A, B/2, C) % C;
    if(B % 2 == 0) {
        return (ret * ret) % C;
    } else {
        return (((A * ret) % C) * ret) % C;
    }
}

int main() {
    ull A, B, C;
    cin >> A >> B >> C;
    cout << pow(A, B, C) << "\n";
}
