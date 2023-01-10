#include <bits/stdc++.h>

#define MOD 900528

using namespace std;

string LISTS;
string PW;
int LEN = 0;
int PW_LEN = 0;

int memos[1000001] = {0, };

int solve() {
    int ans = 0;
    int acc = 1;
    memos[0] = 1;
    for(int i = 1; i < PW_LEN; i++) {
        acc *= LEN;
        acc %= MOD;
        memos[i] = acc;
        ans += acc;
        ans %= MOD;
    }
    ans += 1;
    ans %= MOD;
    
    for(int i = 0; i < PW_LEN; i++) {
        int j = 0;
        int tmp = memos[PW_LEN - i - 1];
        for(; j < LEN; j++) {
            if(PW[i] == LISTS[j]) break;
        }
        tmp *= j;
        ans += tmp;
        ans %= MOD;
    }
    ans %= MOD;
    return ans;
}

int main() {
    cin >> LISTS >> PW;
    LEN = LISTS.length();
    PW_LEN = PW.length();
    cout << solve();
}