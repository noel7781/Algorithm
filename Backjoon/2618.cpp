#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> pathA, pathB;

int n, w;
int cache[1001][1001];
queue<pii> acc;

int man_dist(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int getDistance(int p1, int p2) {
    if(p1 == w || p2 == w) return 0;
    int& ret = cache[p1][p2];
    if(ret != -1) return ret;
    ret = 1e9;
    int next_number = max(p1, p2) + 1;
    int d1 = man_dist(pathA[next_number], pathA[p1]), d2 = man_dist(pathB[next_number], pathB[p2]);
    ret = min(d1 + getDistance(next_number, p2), d2 + getDistance(p1, next_number));
    return ret;
}

void reconstruct(int p1, int p2) {
    if(p1 == w || p2 == w) return;
    int next_number = max(p1, p2) + 1;
    int d1 = man_dist(pathA[next_number], pathA[p1]) + getDistance(next_number, p2), 
        d2 = man_dist(pathB[next_number], pathB[p2]) + getDistance(p1, next_number);
    if(d1 < d2) {
        cout << "1\n";
        reconstruct(next_number, p2);
    } else {
        cout << "2\n";
        reconstruct(p1, next_number);
    }
    return;
}

void solve() {
    int ret = getDistance(0, 0);
    cout << ret << "\n";
    reconstruct(0, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> w;
    pathA.push_back(pii(1, 1));
    pathB.push_back(pii(n, n));
    for(int i = 0; i < w; ++i) {
        int a, b; cin >> a >> b;
        pathA.push_back(pii(a, b));
        pathB.push_back(pii(a, b));
    }
    solve();
}
