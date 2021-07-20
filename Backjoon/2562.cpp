#include <iostream>

using namespace std;

int main() {
    int max_val = 0;
    int idx = 0;
    for(int i = 1; i <= 9; ++i) {
        int a; cin >> a;
        if(max_val < a) {
            max_val = a;
            idx = i;
        }
    }
    cout << max_val << "\n" << idx << "\n";
}
