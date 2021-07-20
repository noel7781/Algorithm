#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> station;
priority_queue<int> pq;
int l, p;

int main() {
    cin >> n;
    station.assign(n, make_pair(0, 0));
    for(int i = 0; i < n; ++i) {
        cin >> station[i].first >> station[i].second;
    }
    sort(station.begin(), station.end());
    cin >> l >> p;
    int pos = 0;
    int idx = 0;
    int ret = 0;
    while(pos < l) {
        pos += p;
        p = 0;
        for(; idx < n;) {
            if(station[idx].first <= pos) {
                pq.push(station[idx].second);
                idx += 1;
            } else {
                break;
            }
        }
        int dist = 0;
        if(idx == n) {
            dist = l - pos;
        } else {
            dist = station[idx].first - pos;
        }
        while(dist > p) {
            if(pq.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int fill = pq.top();
            pq.pop();
            p += fill;
            ret += 1;
        }
    }
    cout << ret << endl;
}
