#include <bits/stdc++.h>
using namespace std;
int N, M, L;
vector<int> V;
bool check(int thr) {
    int built = 0;
    for(int i = 0; i < N+1; i++) {
        int len = V[i+1] - V[i];
        if(len > thr) built += (len / thr) - !(len % thr);
    }
    if(built <= M) return true;
    return false;
}
int main() {
    cin >> N >> M >> L;
    V.resize(N+2);
    V[0] = 0; V[N+1] = L;
    for(int i = 1; i <= N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    int lo = 0, hi = 1000;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}