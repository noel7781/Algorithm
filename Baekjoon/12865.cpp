#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, K;
vector<pii> p;
int cache[102][100001];

int solve(int pos, int carry) {
    if(carry > K) return -1e9;
    int& ret = cache[pos][carry];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = pos+1; i <= N; ++i) {
        ret = max(ret, p[i].second + solve(i, carry + p[i].first));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    p.assign(N+1, make_pair(0, 0));
    for(int i = 1; i <= N; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    cout << solve(0, 0) << "\n";
}