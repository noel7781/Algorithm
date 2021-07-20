#include <iostream>
#include <cstring>

#define MAX 1001

using namespace std;

int coord[MAX][MAX];

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        memset(coord, 0, sizeof(coord));
        int n; cin >> n;
        int ret = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(coord[i][j] == 0) {
                    coord[i][j] = 1;
                    ret += 1;
                    for(int k = 2; i*k <= n && j*k <= n; ++k) {
                        coord[i*k][j*k] = 1;
                    }
                }
            }
        }
        ret += 1;
        cout << ret << "\n";
    }
}