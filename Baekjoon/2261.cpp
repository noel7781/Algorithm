#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> p;
int N;

int euc_dist(pii a, pii b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second-b.second)*(a.second-b.second);
}

int solve(int left, int right) {
    if(right - left == 2) {
        return min(euc_dist(p[left], p[right]), min(euc_dist(p[left], p[left+1]), euc_dist(p[right-1], p[right])));
    }
    if(right - left == 1) {
        int dist = euc_dist(p[left], p[right]);
        return dist;
    }
    int mid = (left + right) / 2;
    int dl = solve(left, mid);
    int dr = solve(mid+1, right);
    int d = min(dl, dr);
    int dm = d;
    vector<pii> band;
    for(int i = left; i <= right; ++i) {
        if((p[mid].first - p[i].first)*(p[mid].first - p[i].first) >= d)
            continue;
        else {
            band.push_back(make_pair(p[i].second, p[i].first));
        }
    }
    sort(band.begin(), band.end());
    int band_size = band.size();
    for(int i = 0; i < band_size - 1; ++i) {
        for(int j = i+1; j < band_size && (band[j].first- band[i].first) * (band[j].first -band[i].first) < d; ++j) {
            dm = min(dm, euc_dist(band[i], band[j]));
        }
    }
    return dm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    p.assign(N, make_pair(0, 0));
    for(int i = 0; i < N; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    cout << solve(0, N-1) << "\n";
}