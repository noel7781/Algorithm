#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int SRC, DST;
vector<vector<pii> > adj;
vector<vector<pii> > rev;
int src_dists[10001];
int ins[10001];
int outs[10001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N+1);
    rev.resize(N+1);
    for(int i = 0; i < M; i++) {
        int from, to, cost; cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        rev[to].push_back({from, cost});
        ins[to]++;
    }
    cin >> SRC >> DST;
    queue<int> q;
    q.push(SRC);
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(auto next: adj[now]) {
            int nextPos = next.first, nextCost = next.second + src_dists[now];
            src_dists[nextPos] = max(src_dists[nextPos], nextCost);
            ins[nextPos]--;
            if(!ins[nextPos]) q.push(nextPos);
        }
    }
    int paths = 0;
    q.push(DST);
    outs[DST] = 1;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(auto next: rev[now]) {
            int nextPos = next.first, nextCost = next.second;
            if(src_dists[nextPos] + nextCost == src_dists[now]) {
                paths++;
                if(outs[nextPos] == 0) {
                    outs[nextPos] = 1;
                    q.push(nextPos);
                }
            }
        }
    }
    cout << src_dists[DST] << "\n";
    cout << paths << "\n";
}