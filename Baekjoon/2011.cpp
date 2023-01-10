#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000;
int len = 0;
int cache[5001];
int solve(string& str, int pos) {
    if(pos == len) return 1;
    int& ret = cache[pos];
    if(ret != -1) return ret;
    ret = 0; 
    if(str[pos] == '0') return 0;
    ret += solve(str, pos+1);
    ret %= MOD;
    if(pos+1 < len) {
        int next = stoi(str.substr(pos, 2));
        if(next > 0 && next <= 26) {
            ret += solve(str, pos+2);
            ret %= MOD;
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    string str; cin >> str;
    len = str.size();
    cout << solve(str, 0);
}