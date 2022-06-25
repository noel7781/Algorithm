#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        vector<int> na;
        int ret = 0;
        for(int i = 0; i < (int)str.size(); i++) {
            ret += min(str[i] - 'A', 'Z' - str[i] + 1);
            if(str[i] != 'A') na.push_back(i);
        }
        int len = str.size();
        if(na.size() == 0) {
            cout << ret << "\n";
        } else if(na.size() == 1) {
            int pos = na.front();
            int move = min(pos, len - pos);
            cout << ret + move << "\n";
        } else {
            int move = min(na.back(), len-na.front());
            for(int j = 0; j < (int)na.size()-1; j++) {
                int pos = na[j];
                int next = j+1;
                int nearest = na[next];
                int lmove = pos, rmove = str.size() - nearest;
                move = min(move, lmove+rmove+min(lmove, rmove));
            }
            cout << ret + move << "\n";
        }
    }
}