#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    int ret = 0;
    int lo = 1, hi = N;
    for(int i = 0; i < K-1; i++) {
        int mid = (lo+hi)>>1;
        if(lo == mid) break;
        lo = mid+1;
        ret++;
    }
    ret += (hi - lo + 1);
    cout << ret << "\n";
}