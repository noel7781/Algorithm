#include <bits/stdc++.h>
using namespace std;
string S; int N;
string solve(int l, int r) {
    string ret = "";
    while(l <= r) {
        if(S[l] < S[r]) {
            ret += S[l++];
        } else if(S[l] > S[r]) {
            ret += S[r--];
        } else {
            int i = l+1, j = r-1;
            while(i <= j) {
                if(S[i] < S[j]) {
                    ret += S[l++];
                    break;
                } else if(S[i] > S[j]) {
                    ret += S[r--];
                    break;
                }
                i++; j--;
            }
            if(i > j) {
                ret += S[l++];
            }
        }
    }
    // if(l == r) {
    //     string ret(1, S[l]);
    //     return ret;
    // }
    // if(S[l] < S[r]) {
    //     return S[l] + solve(l+1, r);
    // } else if(S[l] > S[r]) {
    //     return S[r] + solve(l, r-1);
    // } else {
    //     if(r-l > 1) {
    //         if(S[l+1] < S[r-1]) {
    //             return S[l] + solve(l+1, r);
    //         } else {
    //             return S[r] + solve(l, r-1);
    //         }
    //     } else {
    //         return S[r] + solve(l, r-1);
    //     }
    // }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        char ch; cin >> ch;
        S += ch;
    }
    string ret = solve(0, N-1);
    for(int i = 0; i < N; i++) {
        cout << ret[i];
        if(i % 80 == 79) cout << "\n";
    }
    return 0;
}