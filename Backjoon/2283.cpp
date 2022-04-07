#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<pii> points;
int psum[1000001];
int calc_dist(const pii& p, const pii &thr) {
    if(p.second < thr.first || p.first > thr.second) return 0;
    return min(thr.second, p.second) - max(thr.first, p.first);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; points.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
        for(int j = points[i].first; j < points[i].second; j++) psum[j]++;
    }
    sort(points.begin(), points.end());
    int max_pos = points[N-1].second;
    vector<pii> cur;
    int l = 0, r = 0;
    int tmp = 0;
    while(l <= max_pos) {
        if(tmp < K && r > max_pos) break;
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