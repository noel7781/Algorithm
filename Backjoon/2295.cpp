#include <bits/stdc++.h>
using namespace std;
int N;
bitset<200000001> bs;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> ab;
    cin >> N; V.resize(N);
    for(auto &it: V) {
        cin >> it;
    }
    sort(V.begin(), V.end());
    int ans = -1;
    for(int i = 0; i < N; i++) for(int j = i; j < N; j++) if(V[i]+V[j] <= 200000000) bs[V[i]+V[j]] = 1;
    for(int j = N-1; j >= 0; j--) { for(int i = j-1; i >= 0; i--) { if(bs[V[j]-V[i]]) { ans = V[j]; break; } } if(ans > 0) break; }
    cout << ans << "\n";
}