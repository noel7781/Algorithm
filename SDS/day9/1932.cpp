#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[501][501];
int cache[501][501];

int solve(int y, int x) {
    if(y >= n) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(arr[y][x] + solve(y+1, x), arr[y][x] + solve(y+1,x+1));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << solve(0,0) << "\n";
}