#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;
vector<vector<vector<int> > > stickers;
int solve(int y, int x, int pos) {
    int ret = 0;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    stickers.resize(k);
    for(int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        stickers[i].resize(r, vector<int>(c, 0));
        for(int a = 0; a < r; a++) {
            for(int b = 0; b < c; b++) {
                cin >> stickers[i][a][b];
            }
        }
    }
    cout << solve(0, 0, 0) << "\n";
}
