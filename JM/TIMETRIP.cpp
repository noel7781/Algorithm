#include <iostream>
#include <vector>

#define INF 1e9
#define SHORT 1
#define LONG -1
#define ERROR 100000

using namespace std;

typedef pair<int, int> pii;
int G, W;
vector<vector<pii> > adj;
int maximum_distance = 1e9;
bool is_unreachable = false;

vector<int> bellmanford(int weight) {
    vector<int> upper(G, INF);
    upper[0] = 0;
    bool updated;
    for(int i = 0; i < G; ++i) {
        updated = false;
        for(int here = 0; here < G; ++here) {
            for(int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second * weight;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) {
            break;
        }
    }
    if(upper[1] > INF - ERROR) {
        is_unreachable = true;
        return upper;
    } 
    if(updated) {
        upper.clear();
    }
    return upper;
}

void solve() {
    vector<int> dist_short = bellmanford(SHORT);
    vector<int> dist_long = bellmanford(LONG);
    //printf("size %zu %zu\n", dist_short.size(), dist_long.size());
    if(is_unreachable) {
        printf("UNREACHABLE\n");
        is_unreachable = false;
        return;
    }
    if(dist_short.size() == 0) {
        printf("INFINITY ");
    } else {
        printf("%d ", dist_short[1]);
    }
    if(dist_long.size() == 0) {
        printf("INFINITY\n");
    } else {
        printf("%d\n", -dist_long[1]);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        adj.clear();
        is_unreachable = false;
        cin >> G >> W;
        adj = vector<vector<pii> >(G, vector<pii>());
        for(int i = 0; i < W; ++i) {
            int a, b, d; cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
        }
        solve();
    }
}
