#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v;
int cache[1002][2];

int solve(int pos, bool increase) {
    int& ret= cache[pos][increase];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    // int ret = 0;
    int now = v[pos];
    for(int i = pos+1; i <= N; ++i) {
        int next = v[i];
        if(next > now && increase) {
            ret = max(ret, 1 + solve(i, 1));
        } else if(next < now) {
            ret = max(ret, 1 + solve(i, 0));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    v.assign(N+1, 0);
    for(int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    cout << solve(0, 1) << "\n";
}