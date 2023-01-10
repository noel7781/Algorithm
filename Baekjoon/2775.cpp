#include <iostream>

using namespace std;

int cache[15][15];

void calc_cache() {
    for(int i = 0; i < 15; ++i) {
        cache[0][i] = i;
    }
    for(int i = 1; i < 15; ++i) {
        for(int j = 1; j < 15; ++j) {
            cache[i][j] = cache[i][j-1] + cache[i-1][j];
        }
    }
}

int main() {
    calc_cache();
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        cout << cache[n][k] << "\n";
    }
}
