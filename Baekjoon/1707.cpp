#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int V, E;
int part[20001];

int solve(vector<vector<int> >& adj, int start) {
    part[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int e = 0; e < adj[now].size(); ++e) {
            int next = adj[now][e];
            if(part[next] == part[now]) {
                return 0;
            }
            if(part[next] != 0) continue;
            part[next] = 3-part[now];
            q.push(next);
        }
    }
    return 1;
}

int search(vector<vector<int> >& adj) {
    int ret = 1;
    for(int i = 0; i < V; ++i) {
        if(part[i] == 0) {
            ret &= solve(adj, i);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        memset(part, 0, sizeof(part));
        cin >> V >> E;
        vector<vector<int> > v(V);
        for(int i = 0; i < E; ++i) {
            int e1, e2; cin >> e1 >> e2;
            if(e1 > e2) swap(e1, e2);
            v[e1-1].push_back(e2-1);
            //v[e2-1].push_back(e1-1);
        }
        if(search(v)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
