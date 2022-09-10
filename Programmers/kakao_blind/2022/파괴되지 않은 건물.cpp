#include <string>
#include <vector>

using namespace std;

int R, C;
int records[1002][1002];
int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    R = board.size(); C = board[0].size();
    int answer = 0;
    for(const auto skill: skills) {
        int type = skill[0], r1 = skill[1], c1 = skill[2], r2 = skill[3], c2 = skill[4], degree = skill[5];
        if(type == 1) {
            records[r1][c1] += degree;
            records[r1][c2+1] -= degree;
            records[r2+1][c1] -= degree;
            records[r2+1][c2+1] += degree;
        } else {
            records[r1][c1] -= degree;
            records[r1][c2+1] += degree;
            records[r2+1][c1] += degree;
            records[r2+1][c2+1] -= degree;
        }
    }
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(j == 0) continue;
            records[i][j] += records[i][j-1];
        }
    }
    for(int j = 0; j < C; j++) {
        for(int i = 0; i < R; i++) {
            if(i == 0) continue;
            records[i][j] += records[i-1][j];
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(records[i][j] < board[i][j]) answer++;
        }
    }
    return answer;
}