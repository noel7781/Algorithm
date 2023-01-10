#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<pii> points;
int psum[1000001];
int arr[1000001];
int calc_dist(const pii& p, const pii &thr) {
    if(p.second < thr.first || p.first > thr.second) return 0;
    return min(thr.second, p.second) - max(thr.first, p.first);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; points.resize(N);
    int max_end = -1;
    for(int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        max_end = max(max_end, e);
        arr[s]++;
        arr[e]--;
    }
    psum[0] = arr[0];
    for(int i = 1; i < 1000001; i++) {
        psum[i] = psum[i-1]+arr[i];
    }
    int l = 0, r = 0;
    int tmp = 0;
    while(l <= max_end) {
        if(tmp < K && r > max_end) break;
        if(tmp < K) {
            tmp += psum[r];
            r++;
        } else if(tmp > K) {
            tmp -= psum[l];
            l++;
        } else {
            cout << l << " " << r << "\n";
            return 0;
        }
    }
    cout << "0 0" << "\n";
    return 0;
}