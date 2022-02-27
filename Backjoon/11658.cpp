#include <bits/stdc++.h>
using namespace std;
int N, M;

int board[1025][1025];
struct FenwickTree {
    int tree[1025][1025];
    void init() {
        for(int i = 0; i <= 1024; i++) {
            for(int j = 0; j <= 1024; j++) {
                tree[i][j] = 0;
            }
        }
    }
    void update(int x, int y, int v) {
        for(int i = x; i <= N; i += (i & -i)) {
            for(int j = y; j <= N; j += (j & -j)) {
                tree[i][j] += v;
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for(int i = x; i > 0; i -= (i&-i)) {
            for(int j = y; j > 0; j -= (j&-j)) {
                ret += tree[i][j];
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    struct FenwickTree ft;
    ft.init();
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
            ft.update(i, j, board[i][j]);
        }
    }
    while(M--) {
        int w, x1, y1, x2, y2, c;
        cin >> w;
        if(w == 0) {
            cin >> x1 >> y1 >> c;
            int uv = c - (ft.sum(x1, y1) - ft.sum(x1-1, y1) - ft.sum(x1, y1-1) + ft.sum(x1-1, y1-1));
            ft.update(x1, y1, uv);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            int A = ft.sum(x2, y2);
            int B = ft.sum(x2, y1-1);
            int C = ft.sum(x1-1, y2);
            int D = ft.sum(x1-1, y1-1);
            cout << A - B - C + D << "\n";
        }
    }
}