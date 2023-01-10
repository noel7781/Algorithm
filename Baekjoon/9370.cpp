#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, t;
int s, g, h; 
vector<vector<pii> > graph;

vector<int> dijk(int src) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, src));
    while(!pq.empty()) {
        int cost = pq.top().first, pos = pq.top().second; pq.pop();
        if(dist[pos] < cost) continue;
        for(auto next: graph[pos]) {
            int nextCost = cost + next.second, nextPos = next.first;
            if(dist[nextPos] > nextCost) {
                dist[nextPos] = nextCost;
                pq.push(pii(nextCost, nextPos));
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        graph.clear();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        graph.resize(n+1);
        int len = 1e9;
        for(int i = 0; i < m; ++i) {
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back(pii(b, c));
            graph[b].push_back(pii(a, c));
            if((a == g && b == h) || (a == h && b == g)) len = min(len, c);
        }
        vector<int> from_src = dijk(s);
        graph[g].push_back(pii(0, 0));
        graph[h].push_back(pii(0, 0));
        graph[0].push_back(pii(g, 0));
        graph[0].push_back(pii(h, 0));
        vector<int> from_D1 = dijk(s);
        vector<int> from_D2 = dijk(0);
        vector<int> cand(t);
        for(int i = 0; i < t; ++i) {
            cin >> cand[i];
        }
        sort(cand.begin(), cand.end());
        for(int i = 0; i < t; ++i) {
            int dst = cand[i];
            int min_dist = from_src[dst];
            int d1 = from_D1[0], d2 = from_D2[dst];
            if(min_dist == d1+d2+len) {
                cout << cand[i] << " ";
            }
        }
        cout << "\n";

    }
}
