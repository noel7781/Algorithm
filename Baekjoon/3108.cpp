#include <bits/stdc++.h>

using namespace std;

int N;
int board[1001][1001];

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n): parent(n), rank(n,1) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(board, -1, sizeof(board));
    cin >> N;
    board[500][500] = 0;
    struct DisjointSet ds(N+1);
    for(int i = 1; i <= N; i++) {
        int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
        X1 += 500;
        Y1 += 500;
        X2 += 500;
        Y2 += 500;
        
        if(X1 > X2) swap(X1, X2);
        if(Y1 > Y2) swap(Y1, Y2);
        int xpos = X1, ypos = Y1;
        while(xpos < X2) {
            if(board[xpos][ypos] != -1) {
                ds.merge(board[xpos][ypos], i);
            }
            board[xpos][ypos] = i;
            xpos++;
        }
        while(ypos < Y2) {
            if(board[xpos][ypos] != -1) {
                ds.merge(board[xpos][ypos], i);
            }
            board[xpos][ypos] = i;
            ypos++;
        }
        while(xpos > X1) {
            if(board[xpos][ypos] != -1) {
                ds.merge(board[xpos][ypos], i);
            }
            board[xpos][ypos] = i;
            xpos--;
        }
        while(ypos > Y1) {
            if(board[xpos][ypos] != -1) {
                ds.merge(board[xpos][ypos], i);
            }
            board[xpos][ypos] = i;
            ypos--;
        }
    }
    int ans = 0;
    for(int i = 0; i <= N; i++) {
        if(ds.find(i) == i) ans++;
    }
    cout << ans-1 << "\n";
    return 0;
}
