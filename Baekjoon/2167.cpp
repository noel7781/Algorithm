#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int I, J, X, Y;
int board[301][301];
int psum[301][301];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            psum[i][j] = board[i][j] + (psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]);
        }
    }
    cin >> K;
    while(K--) {
        cin >> I >> J >> X >> Y;
        cout << psum[X][Y] - psum[I-1][Y] - psum[X][J-1] + psum[I-1][J-1] << "\n";
    }
}