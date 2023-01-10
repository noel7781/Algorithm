#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<int> ranks;
int m;


int main() {
    int t; cin >> t;
    while(t--) {
        ranks.clear();
        int g[501][501];
        int in_order[501];
        memset(g, 0, sizeof(g));
        memset(in_order, 0, sizeof(in_order));
        cin >> n; ranks.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> ranks[i];
            for(int j = 0; j < i; ++j) {
                g[ranks[j]][ranks[i]]++;
                in_order[ranks[i]]++;
            }
        }
        cin >> m;
        bool isImpossible = false;
        for(int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            if(g[a][b]) {
                g[a][b] = 0;
                g[b][a] = 1;
                in_order[b]--;
                in_order[a]++;
            }
            else {
                g[b][a] = 0;
                g[a][b] = 1;
                in_order[a]--;
                in_order[b]++;
            }
        }

        bool isOne = true;
        queue<int> q;
        vector<int> orders;
        for(int i = 1 ; i <= n; ++i) {
            if(in_order[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            if(q.size() > 1) {
                isOne = false;
                break;
            }
            int now = q.front(); q.pop();
            orders.push_back(now);
            for(int next = 1; next <= n; ++next) {
                if(g[now][next]) {
                    if(!--in_order[next]) {
                        q.push(next);
                    }
                }
            }
        }

        if(orders.size() < n) isImpossible = true;

        if(!isOne) {
            cout << "?\n";
        } else if(isImpossible) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(auto it: orders) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
}
