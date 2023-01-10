#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> v;
int cache[102][10010];

int solve(int pos, int cost) {
    if(pos > N) return 0;
    int& ret = cache[pos][cost];
    if(ret != -1) return ret;
    ret = solve(pos+1, cost);
    if(v[pos].second <= cost) {
        ret = max(ret, v[pos].first + solve(pos+1, cost - v[pos].second));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    v.reserve(N+1);
    for(int i = 1; i <= N; ++i) {
        cin >> v[i].first;
    }
    for(int i = 1; i <= N; ++i) {
        cin >> v[i].second;
    }
    for(int i = 1;; ++i) {
        if(solve(0, i) >= M) {
            cout << i << "\n";
            break;
        }
    }
}