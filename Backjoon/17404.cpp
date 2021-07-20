#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> R, G, B;
vector<vector<int> > cost;

int cache[3][1003][4][4];

int solve(int start, int pos, int before, int startColor) {
    if(pos == n) {
        return 0;
    }
    int& ret = cache[start][pos][before][startColor];
    if(ret != -1) return ret;
    ret = 1e9;
    if(start == true) {
        for(int i = 0; i < 3; ++i) {
            ret = min(ret, cost[i][0] + solve(false, pos+1, i, i));
        }
        return ret;
    } else {
        if(pos != n-1) {
            for(int i = 0; i < 3; ++i) {
                if(i == before) continue;
                ret = min(ret, cost[i][pos] + solve(false, pos+1, i, startColor));
            }
        } else {
            for(int i = 0; i < 3; ++i) {
                if(i == before || i == startColor) continue;
                ret = min(ret, cost[i][pos] + solve(false, pos+1, i, startColor));
            }
        }
        return ret;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));

    cin >> n;
    R.assign(n, 0); G.assign(n, 0); B.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> R[i];
        cin >> G[i];
        cin >> B[i];
    }
    cost.push_back(R);
    cost.push_back(G);
    cost.push_back(B);
    cout << solve(1, 0, 0, -1) << "\n";
    
}
