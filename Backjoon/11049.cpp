#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> v;
int cache[501][501];

int solve(int left, int right) {
    if(left == right) return 0;
    if(right - left == 1) return v[left].first * v[left].second * v[right].second;
    int& ret = cache[left][right];
    if(ret != -1) return ret;
    ret =  1e9;
    for(int i = left; i <= right; ++i) {
        ret = min(ret, solve(left, i) + solve(i+1, right) + v[left].first * v[i].second * v[right].second);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    v.assign(N, make_pair(0, 0));
    for(int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    cout << solve(0, N-1) << "\n";
}