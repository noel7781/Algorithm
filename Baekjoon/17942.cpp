#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;
int N, M;
int R;
int cost[100005];
set<pii> s;
vector<pii> v[100005];

int solve() {
    int result = 0;
    for(int i = 0; i < M; ++i) {
        int key = s.begin()->first;
        int idx = s.begin()->second;
        s.erase(s.begin());
        for(auto k : v[idx]) {
            auto it = s.find(make_pair(cost[k.first], k.first));
            if(it == s.end()) {
                continue;
            }
            s.erase(it);
            cost[k.first] -= k.second;
            s.insert(make_pair(cost[k.first], k.first));
        }
        result = max(result, key);
        // if(s.empty()) {
        //     break;
        // }
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        int c; cin >> c;
        s.insert(make_pair(c, i));        
        cost[i] = c;
    }
    cin >> R;
    for(int i = 0; i < R; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    cout << solve() << "\n";
}