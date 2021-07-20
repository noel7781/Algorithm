#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> v;
int cache[502];

int solve(int pos) {
    int& ret= cache[pos];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    int now = v[pos].second;
    for(int i = pos+1; i <= N; ++i) {
        int next = v[i].second;
        if(next > now) {
            ret = max(ret, 1 + solve(i));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    v.assign(N+1, make_pair(0, 0));
    for(int i = 1; i <= N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    cout << N - solve(0) << "\n";
}