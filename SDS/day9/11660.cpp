#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int pSum[1025][1025];
int n,m;

void calc_psum(vector<vector<int> >& v) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            pSum[i][j] = v[i][j] + pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int> > v(n+1, vector<int>(n+1, 0));
    for(int i =1 ; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> v[i][j];
        }
    }
    calc_psum(v);
    while(m--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << pSum[c][d] - pSum[c][b-1] - pSum[a-1][d] + pSum[a-1][b-1] << "\n";
    }
}