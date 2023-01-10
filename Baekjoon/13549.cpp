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
    deque<int> dq;
    dq.push_back(N);
    while(!dq.empty()) {
        auto pos = dq.front(); dq.pop_front();
        if(pos == K) {
            cout << dists[pos] << "\n";
            return 0;
        }
        int next_cost = dists[pos] + 1;
        int next_pos = pos+1;
        if(inRange(next_pos) && dists[next_pos] > next_cost) {
            dists[next_pos] = next_cost;
            dq.push_back(next_pos);
        }
        next_pos = pos-1;
        if(inRange(next_pos) && dists[next_pos] > next_cost) {
            dists[next_pos] = next_cost;
            dq.push_back(next_pos);
        }
        next_pos = pos*2;
        if(inRange(next_pos) && dists[next_pos] > dists[pos]) {
            dists[next_pos] = dists[pos];
            dq.push_front(next_pos);
        }
    }
}