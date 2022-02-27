#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;

long long nC2(int n) {
    return 1LL * n * (n-1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for(auto &it: v) cin >> it;
    sort(v.begin(), v.end());
    ll ret = 0;
    ll zero_cnts[20] = {0, };
    ll one_cnts[20] = {0, };
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 20; j++) {
            if(v[i] & (1 << j)) { 
                one_cnts[j]++;
            } else {
                zero_cnts[j]++;
            }
        }
    }
    for(int i = 0; i < 20; i++) {
        long long tmp = (one_cnts[i] + zero_cnts[i]);
        tmp = nC2(tmp);
        tmp -= (nC2(one_cnts[i]) + nC2(zero_cnts[i]));
        ret += (tmp * (1 << i));
    }
    cout << ret << "\n";
}