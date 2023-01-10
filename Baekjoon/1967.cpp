#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int max_dist = 0;
int max_node = 0;
int n = 0;
vector<vector<pii> > v;

void bfs(int s) {
    queue<pii> q;
    vector<bool> is_visit(n+1, 0);
    q.push(make_pair(s, 0));
    is_visit[s] = true;
    while(!q.empty()) {
        int now = q.front().first, dist = q.front().second;
        q.pop();
        for(int i = 0; i < v[now].size(); ++i) {
            if(is_visit[v[now][i].first]) continue;
            is_visit[v[now][i].first] = true;
            q.push(make_pair(v[now][i].first, dist + v[now][i].second));
            if(max_dist < dist + v[now][i].second) {
                max_dist = dist + v[now][i].second;
                max_node = v[now][i].first;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    v.resize(n+1);
    for(int i = 0; i < n-1; ++i) {
        int p, c, w; cin >> p >> c >> w;
        v[p].push_back(make_pair(c, w));
        v[c].push_back(make_pair(p, w));
    }
    bfs(1);
    max_dist = 0;
    bfs(max_node);
    cout << max_dist << "\n";
}
