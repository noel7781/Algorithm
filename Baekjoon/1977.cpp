#include <iostream>
using namespace std;
int M, N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    int ans = 0;
    int minsq = 10001;
    for(int j = 1; j <= 100; j++) {
        int sq = j * j;
        if(M <= sq && sq <= N) {
            ans += sq;
            minsq = min(minsq, sq);
        }
    }
    if(ans != 0) {
        cout << ans << "\n";
        cout << minsq << "\n";
        return 0;
    }
    cout << -1 << "\n";
}