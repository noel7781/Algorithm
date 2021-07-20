#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
int n, k; 
vector<pii> wv;
int cache[101][100001];

int solve(int pos, int weight) {
    if(pos >= n) return 0;
    int& ret = cache[pos][weight];
    if(ret != -1) return ret;
    ret = 0;
    if(wv[pos].first <= weight) {
        ret = max(ret, wv[pos].second + solve(pos+1, weight-wv[pos].first));
        ret = max(ret, solve(pos+1, weight));
    } else {
        ret = solve(pos+1, weight);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    wv.assign(n, pii());
    for(int i = 0; i < n; ++i) {
        cin >> wv[i].first >> wv[i].second;
    }
    cout << solve(0, k) << "\n";
}