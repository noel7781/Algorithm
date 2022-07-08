#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    V.resize(N);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    int ans = 0;

    for(int i = 0; i < N; i++) {
        if(ans + 2 <= V[i]) break;
        ans += V[i];
    }
    cout << ans + 1 << "\n";
}