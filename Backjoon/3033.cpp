#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

typedef long long ll;

int L;
string S;

bool check(int thr) {
    ll ret = 0, pow = 1;
    int cmp = 0;
    vector<int > V[MOD];
    for(int i = 0; i + thr <= L; i++) {
        if(i == 0) {
            for(int j = thr-1; j >= 0; j--) {
                ret += pow * S[j];
                ret %= MOD;
                if(ret < 0) ret += MOD;
                if(j != 0) {
                    pow *= 2;
                    pow %= MOD;
                    if(pow < 0) pow += MOD;
                }
            }
        } else {
            ret = (ret - S[i-1]*pow) *2 + S[i+thr-1];
            ret %= MOD;
            if(ret < 0) ret += MOD;
        }
        if(V[ret].size() > 0) {
            bool is_ok = true;
            for(int idx: V[ret]) {
                is_ok = true;
                for(int p = 0; p < thr; p++) {
                    if(S[idx+p] != S[i+p]) {
                        is_ok = false;
                        break;
                    }
                }
                if(is_ok) return true;
            }
        }
        V[ret].push_back(i);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> S;
    int lo = 0, hi = L;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << "\n";
}