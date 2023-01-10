#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.rbegin(), s2.rend());
    int len = s1.length();
    string ret(len, ' ');
    s1 = s1.substr(0, (len+1)/2);
    s2 = s2.substr(0, len/2);
    int s1_s = 0, s1_e = s1.length()-1;
    int s2_s = 0, s2_e = s2.length()-1;
    int ret_s = 0, ret_e = len-1;
    int turn = 1;
    for(int i = 0; i < len; i++) {
        if(turn) {
            if(s1[s1_s] < s2[s2_s]) {
                ret[ret_s++] = s1[s1_s++];
            } else {
                ret[ret_e--] = s1[s1_e--];
            }
        } else {
            if(s1[s1_s] < s2[s2_s]) {
                ret[ret_s++] = s2[s2_s++];
            } else {
                ret[ret_e--] = s2[s2_e--];
            }
        }
        turn ^= 1;
    }
    cout << ret << "\n";
}