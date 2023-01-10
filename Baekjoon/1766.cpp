#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int> > g;

int main() {
    cin >> n >> m;
    g.assign(n+1, vector<int>());
    int ins[32001];
    memset(ins, 0, sizeof(ins));
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        ins[b]++;
    }

    vector<int> order;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 1; i <= n; ++i) {
        if(ins[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.top(); q.pop();
        order.push_back(now);
        for(auto next: g[now]) {
            if(!--ins[next]) {
                q.push(next);
            }
        }
    }
    for(auto it: order) {
        cout << it << " ";
    }
    cout << "\n";

}
