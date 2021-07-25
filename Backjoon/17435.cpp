#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int m;
vector<int> v;
int n, x;

int ans[20][200001];

void calculate_ans() {
    for(int i = 1; i <= m; ++i) {
        ans[0][i] = v[i];
    }
    for(int i = 1; i <= 19; ++i) {
        for(int j = 1; j <= m; ++j) {
            ans[i][j] = ans[i-1][ans[i-1][j]];
        }
    }
}

int solve(int n, int x) {
    for(int i = 19; i >= 0; --i) {
        if(n & (1 << i)) {
            x = ans[i][x];
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    v.resize(m+1);
    for(int i = 1; i <= m; ++i) {
        cin >> v[i];
    }
    calculate_ans();
    int q; cin >> q;
    while(q--) {
        cin >> n >> x;
        cout << solve(n, x) << "\n";
    }
}
