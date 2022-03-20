#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, S;
int mid;
vector<int> l,r;
vector<int> sl, sr;
ll ret = 0;
bool is_visit[1<<20];
void solve(vector<int>& sv, vector<int>& v, int acc, int pos, int used, int thr) {
    if(used && !is_visit[used]) {
        is_visit[used] = 1;
        sv.push_back(acc);
        if(acc == S) ret++;
    }
    if(pos == thr) return;
    solve(sv, v, acc, pos+1, used, thr);
    solve(sv, v, acc+v[pos], pos+1, used | (1 << pos), thr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    mid = N/2;
    l.resize(mid); r.resize(N-mid);
    for(auto &it: l) cin >> it; for(auto &it: r) cin >> it;
    solve(sl, l, 0, 0, 0, mid);
    memset(is_visit, 0, sizeof(is_visit));
    solve(sr, r, 0, 0, 0, N-mid);
    sort(sr.begin(), sr.end());
    for(auto num: sl) {
        auto it = equal_range(sr.begin(), sr.end(), S-num);
        ret += (it.second - it.first);
    }
    cout << ret << "\n";
}