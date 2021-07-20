#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;

int k, n, m;
int src, dst;

vector<vector<tiii> > adj;

int solve() {
    int ret = -1;

    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push(make_tuple(0, k, src));
    //vector<pii> visit(n+1, make_pair(1e9, 0));

    int visit[2001][201];
    for(int i = 0; i < 2001; ++i) {
        for(int j = 0; j <201; ++j) {
            visit[i][j] = 1e9;
        }
    }

    while(!pq.empty()) {
        tiii curr = pq.top();
        pq.pop();
        int cost = get<0>(curr), thick = get<1>(curr), now = get<2>(curr);
        //cout<<"cost: "<<cost<< " and thick:" << thick << "and now: "<<now<<endl;
        if(now == dst) return cost;
        for(int i = 0; i < adj[now].size(); ++i) {
            int next = get<0>(adj[now][i]);
            int nextCost = cost + get<1>(adj[now][i]);
            int nextThick = thick - get<2>(adj[now][i]);
            if(nextThick <= 0) continue;
            if(visit[next][nextThick] > nextCost) {
                visit[next][nextThick] = nextCost;
                pq.push(make_tuple(nextCost, nextThick, next));
            }
            /*
            if(visit[next].first < nextCost && visit[next].second > nextThick) continue;
            if(visit[next].first > nextCost && visit[next].second < nextThick) {
                visit[next].first = nextCost;
                visit[next].second = nextThick;
                pq.push(make_tuple(nextCost, nextThick, next));
            } else {
                pq.push(make_tuple(nextCost, nextThick, next));
            }
            */
        }

    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n >> m;
    adj.assign(n+1, vector<tiii>());
    for(int i = 0; i < m; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].push_back(make_tuple(b, c, d));
        adj[b].push_back(make_tuple(a, c, d));
    }
    cin >> src >> dst;
    cout << solve() << "\n";
}
