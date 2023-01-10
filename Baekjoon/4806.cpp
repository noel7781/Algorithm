#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int ret = 0;
    while(getline(cin, s)) ret++;
    cout << ret << "\n";
}
