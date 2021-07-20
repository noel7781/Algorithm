#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    int lo = 1, hi = 1e9;
    int mid = (lo + hi) / 2;
    int ret = 1e9;
    while(lo <= hi) {
        int cnt = 0;
        mid = (lo + hi) / 2;
        for(int i = 1; i <= n; ++i) {
            cnt += min(mid / i, n);
        }
        if(cnt >= k) {
            hi = mid - 1;
            ret = min(ret, mid);
        } else {
            lo = mid + 1;
        }
    }
    cout << ret << "\n";
}
