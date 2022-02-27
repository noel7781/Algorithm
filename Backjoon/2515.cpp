#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, S;
vector<pii> V;

int dp[300002];

int search(int mid, int thr) {
    return V[mid].first <= thr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    V.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    sort(V.begin(), V.end());
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        int H = V[i].first, C = V[i].second;
        if(V[1].first <= H - S) {
            int lo = 1, hi = N+1;
            while(lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if(search(mid, H-S)) lo = mid;
                else hi = mid;
            }
            dp[i] = max(dp[i-1], C + dp[lo]);
        }
        else
            dp[i] = max(dp[i-1], C);
    }
    cout << dp[N] << "\n";
}