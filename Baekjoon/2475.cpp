#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    vector<int> v(5, 0);
    for(auto &it: v) cin >> it;
    int sum = 0;
    for(auto it: v) {
        sum += (it * it);
    }
    cout << sum % 10 << "\n";

}
