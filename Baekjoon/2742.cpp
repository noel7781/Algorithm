#include <ios>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int i = t; i >= 1; --i) {
        cout << i << "\n";
    }
}
