#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        string num = to_string(n);
        int size = num.size();
        bool flag = false;
        for(int i = 0; i < size / 2; i++) {
            if(num[i] != num[size-i-1]) {
                cout << "no\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "yes\n";
    }
}