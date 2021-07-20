#include <iostream>
#include <vector>
#include <cstring>

#define A_TURN 1
#define B_TURN -1

using namespace std;

int n;

int cache[51][51][3];

int solve(vector<int>& v, int lpos, int rpos, int turn) {
    if(lpos > rpos) return 0;
    int& ret = cache[lpos][rpos][turn+1];
    if(ret != -1e9) {
        return ret;
    }
    if(turn == A_TURN) {
        ret = -1e9;
        int cand_l = turn*v[lpos] + solve(v, lpos+1, rpos, -turn);
        int cand_r = turn*v[rpos] + solve(v, lpos, rpos-1, -turn);
        if(rpos - lpos >= 1) {
            ret = max(solve(v, lpos+2, rpos, -turn), solve(v, lpos, rpos-2, -turn));
        }
        ret = max(ret, max(cand_l, cand_r));
    } else {
        ret = 1e9;
        int cand_l = turn*v[lpos] + solve(v, lpos+1, rpos, -turn);
        int cand_r = turn*v[rpos] + solve(v, lpos, rpos-1, -turn);
        if(rpos - lpos >= 1) {
            ret = min(solve(v, lpos+2, rpos, -turn), solve(v, lpos, rpos-2, -turn));
        }
        ret = min(ret, min(cand_l, cand_r));
    }
    return ret;
}

/*
 * BOOK Solution
    const int EMPTY = -987654321;
    int n, board[50];
    int cache[50][50];
    int play(int left, int right) {
        if(left > right> return 0;
        int& ret = - cache[left][right];
        if(ret != -1) return ret;
        ret = max(board[left] - play(left+1, right),
                  board[right] - play(left, right-1));
        if(right - left + 1 >= 2) {
            ret = max(ret, -play(left+2, right));
            ret = max(ret, -play(left, right-2));
        }
        return ret;
    }
*/
int main() {
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 51; ++i) {
            for(int j = 0; j < 51; ++j) {
                for(int k = 0; k < 3; ++k) {
                    cache[i][j][k] = -1e9;
                }
            }
        }
        cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cout << solve(v, 0, n-1, A_TURN) << "\n";
    }
}
