#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int s, d;
vector<vector<pii> > v;

void solve() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    vector<int> dist(N+1, 1e9);
    dist[s] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first, now = pq.top().second;
        pq.pop();
        if(dist[now] < cost) continue;
        for(int i = 0; i < v[now].size(); ++i) {
            int next = v[now][i].first;
            int nextDist = v[now][i].second + cost;
            if(dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }
    cout << dist[d] << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N+1);
    for(int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    cin >> s >> d;
    solve();
}