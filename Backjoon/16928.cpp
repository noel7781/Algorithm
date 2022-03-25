#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int board[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 100; i++) board[i] = i;
    cin >> N >> M;
    for(int i = 0; i < N+M; i++) {
        int p1, p2; cin >> p1 >> p2; board[p1] = p2;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    vector<int> dists(101, 1e9);
    dists[1] = 0;
    int ret = 0;
    while(!pq.empty()) {
        auto [cost, cur_pos] = pq.top(); pq.pop();
        if(cur_pos == 100) {
            ret = cost;
            break;
        }
        if(dists[cur_pos] < cost) continue;
        for(int j = 1; j <= 6; j++) {
            if(cur_pos+j <= 100) {
                int next_pos = board[cur_pos+j];
                if(dists[next_pos] > cost+1) {
                    dists[next_pos] = cost+1;
                    pq.push({cost+1, next_pos});
                }
            }
        }
    }
    cout << ret << "\n";
}