#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int N, M;
vector<pii> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    ll prev_max = 0;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll cur_max = 0, cur_min = 0;
    ll ret = 0;
    for(int i = 0; i < N; i++) {
        if(v[i].first < v[i].second) continue;
        if(cur_max == 0) {
            cur_max = v[i].first, cur_min = v[i].second;
        }
        if(v[i].second > cur_max) {
            ret += (cur_max - prev_max);
            ret += 2*(cur_max - cur_min);
            prev_max = cur_max;
            cur_max = v[i].first, cur_min = v[i].second;
        } else {
            cur_max = v[i].first, cur_min = min(v[i].second, cur_min);
        }
    }
    ret += (cur_max - prev_max);
    ret += 2*(cur_max - cur_min);
    ret += (M - cur_max);
    cout << ret << "\n";
}