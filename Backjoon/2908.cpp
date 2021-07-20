#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string n1, n2;
    cin >> n1 >> n2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    if(stoi(n1) > stoi(n2)) cout << n1 << "\n";
    else cout << n2 << "\n";
}
