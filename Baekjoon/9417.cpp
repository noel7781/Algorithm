#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string str; 
        getline(cin, str);
        vector<int> num;
        stringstream ss(str);
        int tmp;
        while(ss >> tmp) {
            num.push_back(tmp);
        }
        int len = num.size();
        int ans = 1;
        for(int i = 0; i < len; i++) {
            for(int j = i+1; j < len; j++) {
                ans = max(ans, gcd(num[i], num[j]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}