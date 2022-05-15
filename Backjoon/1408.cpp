#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    int h1, h2, m1, m2, s1, s2;
    h1 = stoi(str1.substr(0, 2));
    h2 = stoi(str2.substr(0, 2));
    m1 = stoi(str1.substr(3, 2));
    m2 = stoi(str2.substr(3, 2));
    s1 = stoi(str1.substr(6, 2));
    s2 = stoi(str2.substr(6, 2));
    m1 += (h1 * 60);
    m2 += (h2 * 60);
    s1 += (m1 * 60);
    s2 += (m2 * 60);
    int diff = s2 - s1;
    if(diff < 0) diff += (24 * 60 * 60);
    string H = to_string(diff / 3600);
    string M = to_string((diff % 3600)/60);
    string S = to_string(diff % 60);
    cout << (H.length() == 1 ? "0"+H : H) << ":" << (M.length() == 1 ? "0"+M : M) <<":" << (S.length() == 1 ? "0"+S:S) << "\n";
}