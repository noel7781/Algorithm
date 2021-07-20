#include <iostream>
#include <vector>
#include <cstring>

#define MOD 100000

using namespace std;

int dX[] = {0, 1}; int dY[] = {1, 0};
int cache[102][102][2][3];

int h, w;
vector<vector<int> > intersection;

int solve(int ypos, int xpos, int d, int c) {
    // printf("y %d x %d d %d c %d\n", ypos, xpos, d, c);
    if(ypos == h && xpos == w) return 1;
    if(ypos > h || xpos > w) return 0;
    int& ret = cache[ypos][xpos][d][c];
    if(ret != -1) return ret;
    ret = 0;
    if(c == 1) {
        ret = solve(ypos+dY[d],xpos+dX[d],d, 2) % MOD;
    } else {
        ret = (solve(ypos+dY[d],xpos+dX[d], d, 2) % MOD
             +solve(ypos+dY[d^1],xpos+dX[d^1],d^1, 1) % MOD) % MOD;
    }
    return ret % MOD;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> w >> h;    
    // 0 위 1 오
    int ret = (solve(1, 2, 1, 2) + solve(2, 1, 0, 2)) % MOD;
    cout << ret << "\n";
}