#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int board[41][41];
vector<vector<vector<int> > > stickers;

bool put_sticker(vector<vector<int> >& sticker) {
    int R = sticker.size(), C = sticker[0].size();
    bool is_ok = true;
    for(int i = 0; i + R <= N; i++) {
        for(int j = 0; j + C <= M; j++) {
            is_ok = true;
            for(int p = 0; p < R; p++) {
                for(int q = 0; q < C; q++) {
                    if(board[i+p][j+q] == 1 && sticker[p][q] == 1) {
                        is_ok = false;
                        break;
                    }
                }
                if(!is_ok) break;
            }
            if(is_ok) {
                for(int p = 0; p < R; p++) {
                    for(int q = 0; q < C; q++) {
                        if(sticker[p][q] == 1) {
                            board[i+p][j+q] = 1;
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void rotate_sticker(vector<vector<int> >& sticker) {
    int R = sticker.size(), C = sticker[0].size();
    int next_R = C, next_C = R;
    vector<vector<int> > next_sticker(next_R, vector<int>(next_C, 0));
    for(int i = 0; i < next_R; i++) {
        for(int j = 0; j < next_C; j++) {
            next_sticker[i][j] = sticker[R-j-1][i];
        }
    }
    sticker = next_sticker;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    stickers.resize(K);
    for(int i = 0; i < K; i++) {
        int R, C; cin >> R >> C;
        stickers[i].resize(R, vector<int> (C, 0));
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                cin >> stickers[i][j][k];
            }
        }
    }
    for(int i = 0; i < K; i++) {
        bool is_success = false;
        for(int t = 0; t < 4; t++) {
            if(put_sticker(stickers[i])) {
                is_success = true;
                break;
            } else {
                rotate_sticker(stickers[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans += board[i][j];
        }
    }
    cout << ans << "\n";
}