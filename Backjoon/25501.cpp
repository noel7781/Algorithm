#include <bits/stdc++.h>
using namespace std;
int rec_cnt = 0;

int recursion(string& s, int l, int r){
    rec_cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string& s){
    return recursion(s, 0, s.length()-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i = 0; i < T; i++) {
        rec_cnt = 0;
        string str; cin >> str;
        cout << isPalindrome(str) << " " << rec_cnt << "\n";
    }
}