#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int PIV = (1 << 12);

struct segTree {
    int n;
    vector<vector<int> > a;
    segTree(int n) : n(n), a(2*n, vector<int>(2*n, 0)) {}
    void init(const vector<vector<int> >& v) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a[n+i][n+j] = v[i][j];
            }
        }
        for(int i = n; i < 2*n; ++i) {
            for(int j = n-1; j >= 0; --j) {
                a[i][j] = a[i][j<<1] + a[i][j<<1 | 1];
            }
        }
        for(int i = n; i < 2*n; ++i) {
            for(int j = n-1; j >= 0; --j) {
                a[i][j] = a[i<<1][j] + a[i<<1 | 1][j];
            }
        }
    }
    void update(int x, int y, int v) {
        a[x+n][y+n] = v;
        for(int i = y+n; i > 1; i >>= 1)  a[x+n][i>>1] = a[x+n][i] + a[x+n][i^1];
        for(x = x+n; x > 1; x >>= 1){
          for(int i = y+n; i >= 1; i >>= 1){
            a[x>>1][i] = a[x][i]+a[x^1][i];        
          }
        }
    }
};

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    segTree t(n);
    while(m--) {
        int c; cin >> c;
        if(c == 1) {
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << t.query(x1, y1, x2, y2) << "\n";
        } else {
            int x1,y1,v; cin >> x1 >> y1 >> v;
            t.update(x1, y1, v);
        }
    }
}
