#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K;
bool inRange(int x) {
    return 0 <= x && x <= 100000;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    vector<int> dists(100001, 1e9);
    dists[N] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, N});
    while(!pq.empty()) {
        auto [cost, pos] = pq.top(); pq.pop();
        if(pos == K) {
            cout << cost << "\n";
            return 0;
        }
        if(dists[pos] < cost) continue;
        int next_cost = cost+1;
        int next_pos = pos+1;
        if(inRange(next_pos) && dists[next_pos] > next_cost) {
            dists[next_pos] = next_cost;
            pq.push({next_cost, next_pos});
        }
        next_pos = pos-1;
        if(inRange(next_pos) && dists[next_pos] > next_cost) {
            dists[next_pos] = next_cost;
            pq.push({next_cost, next_pos});
        }
        next_pos = pos*2;
        if(inRange(next_pos) && dists[next_pos] > cost) {
            dists[next_pos] = cost;
            pq.push({cost, next_pos});
        }
    }

}