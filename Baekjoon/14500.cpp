#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<vector<int> > v;

int dx[19][4] = {{0,1,2,3}, 
                 {0,1,2,0}, {0,1,2,1}, {0,1,2,2},
                 {0,1,0,0}, {0,1,0,1}, {0,1,1,1}, {0,1,-1,0}, {0,1,1,2},
                 {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,2}, {0,-1,0,1}, {0,-2,-1,0}, {0,0,1,1}, {0,0,0,-1}, {0,-1,0,0}, {0,-1,0,-1}};
int dy[19][4] = {{0,0,0,0}, 
                 {0,0,0,1}, {0,0,0,1}, {0,0,0,1},
                 {0,0,1,2}, {0,0,1,1}, {0,0,1,2}, {0,0,1,1}, {0,0,1,1},
                 {0,1,2,3}, {0,1,2,2}, {0,1,1,2}, {0,1,1,1}, {0,1,1,1}, {0,1,1,1}, {0,1,1,2}, {0,1,2,2}, {0,1,1,2}, {0,1,1,2}};

int tetro(int y, int x, int shape) {
    int ret = 0;
    for(int i = 0; i < 4; ++i) {
        int ypos = y + dy[shape][i], xpos = x + dx[shape][i];
        if(ypos < 0 || xpos < 0 || ypos >= n || xpos >= m) return 0;
        ret += v[ypos][xpos];
    }
    return ret;
}

int solve() {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            for(int k = 0; k < 19; ++k) {
                ret = max(ret, tetro(i, j, k));
            }
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    cout << solve() << "\n";
}
