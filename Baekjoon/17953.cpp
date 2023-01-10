#include <iostream>
#include <cstring>

using namespace std;

int pleasure[12][100005];
int cache[12][100005];
int N, M;

int solve(int before, int pos) {
    if(pos == N+1) {
        return 0;
    }
    int& ret = cache[before][pos];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i = 1; i <= M; ++i) {
        if(i == before) {
            ret = max(ret, (pleasure[i][pos])/2 + solve(i, pos+1));
        } else {
            ret = max(ret, pleasure[i][pos] + solve(i, pos+1));
        }   
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(pleasure, 0, sizeof(pleasure));
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> pleasure[i][j];
        }
    }
    cout << solve(0, 1) << "\n";
}