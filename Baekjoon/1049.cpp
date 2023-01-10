#include <bits/stdc++.h>
using namespace std;
int N, M;
int min_6 = 1e9, min_1 = 1e9;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while(M--) {
        int x, y; cin >> x >> y;
        min_6 = min(min_6, x); min_1 = min(min_1, y);
    }
    int ret = min_1 * N;
    ret = min(ret, (N/6) * min_6 + (N%6) * min_1);
    ret = min(ret, (N/6) * min_6 + !(!(N%6)) * min_6);
    cout << ret << "\n";
}