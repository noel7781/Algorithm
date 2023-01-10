#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int m = -1, n = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> m >> n;
        if(m == 0 && n == 0) return 0;
        vector<vector<pii> > adj(m, vector<pii>());
        int total = 0;
        int ret = 0;
        for(int i = 0; i < n; i++) {
            int p1, p2, dist; cin >> p1 >> p2 >> dist;
            adj[p1].push_back(pii(p2, dist));
            adj[p2].push_back(pii(p1, dist));
            total += dist;
        }
        vector<int> visited(m, 0);
        priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
        for(auto it: adj[0]) {
            pq.push(tiii(it.second, 0, it.first));
        }
        visited[0] = 1;
        int iter = 0;
        while(iter < m-1) {
            tiii now = pq.top(); pq.pop();
            int p1 = get<1>(now), p2 = get<2>(now), dist = get<0>(now);
            if(visited[p1] && visited[p2]) continue;
            else {
                if(visited[p1] == 1) swap(p1, p2);
                for(auto it: adj[p1]) {
                    pq.push(tiii(it.second, p1, it.first));
                }
                visited[p1] = 1;
                ret += dist;
                iter += 1;
            }
        }
        cout << total - ret << "\n";
    }
    return 0;
}
