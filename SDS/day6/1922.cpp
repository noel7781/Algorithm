#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, m;

vector<bool> visit;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    visit.assign(n+1, 0);
    vector<vector<pii> > graph;
    graph.resize(n+1);
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(pii(c, b));
        graph[b].push_back(pii(c, a));
    }
    int ret = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 0; i < graph[1].size(); ++i) {
        pii next = graph[1][i];
        pq.push(next);
    }
    visit[1] = true;
    int pop_count = 0;
    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        if(visit[top.second]) continue;
        visit[top.second] = true;
        ret += top.first;
        pop_count += 1;
        if(pop_count == n-1) break;
        int now = top.second; int now_cost = top.first;
        for(int i = 0; i < graph[now].size(); ++i) {
            pii next = graph[now][i];
            int next_cost = next.first, next_pos = next.second;
            if(visit[next_pos]) continue;
            pq.push(next);
        }
    }
    cout << ret << "\n";
}