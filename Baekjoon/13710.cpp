#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> v;
vector<ll> one_cnts(31, 0);
vector<ll> zero_cnts(31, 0);
vector<ll> prev_zero_chg(31, 0);
vector<ll> prev_one_chg(31, 0);
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        for(int k = 0; k <= 30; k++) {
            if(x & (1 << k)) {
                ll cur_zero_cnt = zero_cnts[k];
                ll cur_one_cnt = one_cnts[k];
                one_cnts[k] += prev_zero_chg[k];
                one_cnts[k] += 1;
                zero_cnts[k] += prev_one_chg[k];
                prev_one_chg[k] = one_cnts[k] - cur_one_cnt;
                prev_zero_chg[k] = zero_cnts[k] - cur_zero_cnt;
            }
            else {
                ll cur_zero_cnt = zero_cnts[k];
                ll cur_one_cnt = one_cnts[k];
                one_cnts[k] += prev_one_chg[k];
                zero_cnts[k] += prev_zero_chg[k];
                zero_cnts[k] += 1;
                prev_one_chg[k] = one_cnts[k] - cur_one_cnt;
                prev_zero_chg[k] = zero_cnts[k] - cur_zero_cnt;
            }
        }
    }
    ll ret = 0;
    for(int k = 0; k <= 30; k++) {
        ret += one_cnts[k] * (1 << k);
    }
    cout << ret << "\n";
}