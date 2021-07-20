#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int start = 1;
    while(start <= n) {
        for(int i = 0; i < n-start; ++i) {
            cout << " ";
        }
        for(int i = 0; i < start; ++i) {
            cout << "*";
        }
        cout << "\n";
        start += 1;
    }
}
