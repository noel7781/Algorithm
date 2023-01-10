#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int N;
vector<pii> V;
bool judge(int p, int q, int r) {
    ll xdiff1 = V[p].first - V[q].first;
    ll xdiff2 = V[q].first - V[r].first;
    ll xdiff3 = V[r].first - V[p].first;
    ll ydiff1 = V[p].second - V[q].second;
    ll ydiff2 = V[q].second - V[r].second;
    ll ydiff3 = V[r].second - V[p].second;
    ll a = xdiff1 * xdiff1 + ydiff1 * ydiff1;
    ll b = xdiff2 * xdiff2 + ydiff2 * ydiff2;
    ll c = xdiff3 * xdiff3 + ydiff3 * ydiff3;
    if(a == b+c || b == a + c || c == a + b) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            for(int k = j+1; k < N; k++) {
                if(judge(i, j, k)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}