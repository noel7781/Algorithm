#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string str;
        getline(cin, str);
        if(str[0] > 'Z') str[0] -= 32;
        cout << str << "\n";
    }
}