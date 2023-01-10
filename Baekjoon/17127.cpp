#include <bits/stdc++.h>
using namespace std;
int N; vector<int> V;
int solve(int count, int pos) {
    if(count == 4) {
        return 0;
    }
    int ret = 0;
    int acc = 1;
    for(int j = pos; j + (4-count) <= N; j++) {
        acc *= V[j];
        ret = max(ret, acc + solve(count+1, j+1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    cout << solve(0, 0);
}