#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;

int cache[101][1<<15];

int N, M, K;
vector<int> jewel_islands;
vector<vector<pii> > g;

int bitCount(int x) {
    int count = 0;
    while(x > 0) {
        count += x % 2;
        x /= 2;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("test.in","r", stdin);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M >> K;
    jewel_islands.resize(K);
    g.resize(N+1);
    for(auto &it: jewel_islands) cin >> it;
    for(int i = 0; i < M; i++) {
        int i1, i2, w; cin >> i1 >> i2 >> w;
        g[i1].push_back(pii(i2, w));
        g[i2].push_back(pii(i1, w));
    }
    int ret = 0;
    // pos visit
    int is_visited[101][1<<14];
    memset(is_visited, -1, sizeof(is_visited));
    queue<pii> q;
    q.push(pii(1, 0));
    while(!q.empty()) {
        auto [pos, visit] = q.front(); q.pop();
        if(is_visited[pos][visit] > bitCount(visit)) continue;
        if(pos == 1) {
            int jewel_island = -1;
            for(int i = 0; i < jewel_islands.size(); i++) {
                if(jewel_islands[i] == 1) {
                    jewel_island = i;
                    break;
                }
            }
            if(jewel_island == -1) {
                ret = max(ret, bitCount(visit));
            } else {
                if(visit & (1 << jewel_island))
                    ret = max(ret, bitCount(visit));
                else
                    ret = max(ret, 1+bitCount(visit));
            }
        }
        for(auto next: g[pos]) {
            auto [nextPos, limit] = next;
            int jewel_island = -1;
            for(int i = 0; i < jewel_islands.size(); i++) {
                if(jewel_islands[i] == nextPos) {
                    jewel_island = i;
                    break;
                }
            }
            if(jewel_island == -1) {
                if(is_visited[nextPos][visit] < bitCount(visit) && bitCount(visit) <= limit) {
                    is_visited[nextPos][visit] = bitCount(visit);
                    q.push(pii(nextPos, visit));
                }
            } else {
                if(is_visited[nextPos][visit] < bitCount(visit) && bitCount(visit) <= limit) {
                    is_visited[nextPos][visit] = bitCount(visit);
                    q.push(pii(nextPos, visit));
                }
                if(!(visit & (1 << jewel_island))) {
                    visit |= (1 << jewel_island);
                    if(is_visited[nextPos][visit] < bitCount(visit) && bitCount(visit) <= limit) {
                        is_visited[nextPos][visit] = bitCount(visit);
                        q.push(pii(nextPos, visit));
                    }
                    visit &= ~(1 << jewel_island);
                }

            }
        }

    }
    cout << ret << "\n";
}