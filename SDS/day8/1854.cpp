#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<vector<pii> > g(n+1);
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(pii(b, c));
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<priority_queue<int> > vpq(n+1);
    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    vpq[1].push(0);
    pq.push(pii(0, 1));
    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int cost = top.first, pos = top.second;
        for(auto next:g[pos]) {
            int nextCost = cost + next.second, nextPos = next.first;
            if(vpq[nextPos].size() < k) {
                vpq[nextPos].push(nextCost);
                pq.push(pii(nextCost, nextPos));
            } else if(vpq[nextPos].top() > nextCost) {
                vpq[nextPos].pop();
                vpq[nextPos].push(nextCost);
                pq.push(pii(nextCost, nextPos));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(vpq[i].size() < k) cout << -1 << "\n";
        else cout << vpq[i].top() << "\n";
    }
}