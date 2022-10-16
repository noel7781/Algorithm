#include <bits/stdc++.h>
using namespace std;
int N, M;
int A, B;
vector<vector<int> > adj;
int ins[1001];
int dists[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dists, 0x3f, sizeof(dists));
    cin >> N >> M;
    adj.resize(N+1);
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        ins[B]++;
    }
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(!ins[i]) {
            dists[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int next: adj[now]) {
            ins[next]--;
            if(!ins[next]) {
                q.push(next);
                dists[next] = dists[now] + 1;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        cout << dists[i] << " ";
    }
    cout << "\n";
    return 0;
}