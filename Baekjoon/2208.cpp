#include <bits/stdc++.h>

using namespace std;

int N, M;

int values[100001];
int pSum[100001];

void precalc() {
    for(int i = 1; i <= N; i++) {
        pSum[i] = pSum[i-1] + values[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> values[i];
    }
    precalc();
    int cur_max = -1e9;
    int ans = 0;
    for(int i = N; i >= 1; i--) {
        if(cur_max >= pSum[i]) continue;
        cur_max = pSum[i];
        if(i - M < 0) break;
        int min_elems = *min_element(pSum, pSum+i-M+1);
        ans = max(ans, cur_max - min_elems);
    }
    cout << ans << "\n";

}
