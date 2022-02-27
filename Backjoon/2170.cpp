#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<pii> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
        if(V[i].first > V[i].second) swap(V[i].first, V[i].second);
    }
    sort(V.begin(), V.end());
    int l = -1e9-1, r= -1e9-1;
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int x = V[i].first, y = V[i].second;
        if(x > r) {
            ret += (r-l);
            l = x; r = y;
        } else if(y < r) {
            continue;
        } else {
            r = max(r, y);
        }
    }
    ret += (r-l);
    cout << ret << "\n";
}