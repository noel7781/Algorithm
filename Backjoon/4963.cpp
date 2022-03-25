#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int W, H;
int board[60][60];
bool inRange(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1) {
        cin >> W >> H;
        if(W == 0 && H == 0) return 0;
        for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> board[i][j];
        int index = 2;
        for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
            if(board[i][j] == 1) {
                board[i][j] = index;
                queue<pii> q;
                q.push({i, j});
                while(!q.empty()) {
                    auto [cy, cx] = q.front(); q.pop();
                    for(int j = 0; j < 8; j++) {
                        int ny = cy+dy[j], nx = cx+dx[j];
                        if(inRange(ny, nx)) {
                            if(board[ny][nx] == 1) {
                                board[ny][nx] = index;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
                index++;
            } 
        }

        cout << index-2 << "\n";
    }

}