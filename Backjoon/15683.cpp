#include <iostream>
#include <vector>
#include <cstring>

#define wall int(-1)

using namespace std;

typedef pair<int, int> pii;

int col, row; 
int cctvCnt;
// right down left up
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

vector<pair<pii, int> > cctvs;
vector<pii> walls;
void printState(vector<vector<int> >& office) {
    printf("-----------------------------------\n");
    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            printf("%d ", office[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

void spread(vector<vector<int> >& office, int y, int x, int direction, int put) {
    direction %= 4;
    int dx = dX[direction], dy = dY[direction];
    int next_y = y + dy, next_x = x + dx;
    while(1) {
        if(next_y < 0 || next_x < 0 || next_y >= col || next_x >= row) break;
        if(office[next_y][next_x] == wall) break;
        if(put == 1) {
            if(office[next_y][next_x] == 0 || office[next_y][next_x] >= 10)
                office[next_y][next_x] += 10 * put;
        } else {
            if(office[next_y][next_x] >= 10)
                office[next_y][next_x] += 10 * put;
        }
        next_y = next_y + dy; next_x = next_x + dx;
    }
}

int solve(vector<vector<int> >& office, int pos) {
    if(pos == cctvCnt) {
    //    printState(office);
        int ret = 0;
        for(int i = 0; i < col; ++i) {
            for(int j = 0; j < row; ++j) {
                if(office[i][j] == 0) {
                    ret += 1;
                }
            }
        }
        return ret;
    } 
    pair<pii, int> cctvInfo = cctvs[pos];
    int ypos = cctvInfo.first.first, xpos = cctvInfo.first.second, n = cctvInfo.second;
    int ret = 1e9;
    if(n == 1) {
        for(int i = 0; i < 4; ++i) {
            spread(office, ypos, xpos, i, 1);
            ret = min(ret, solve(office, pos+1));
            spread(office, ypos, xpos, i, -1);
        }
    } else if(n == 2) {
        for(int i = 0; i < 2; ++i) {
            spread(office, ypos, xpos, i, 1);
            spread(office, ypos, xpos, 2+i, 1);
            ret = min(ret, solve(office, pos+1));
            spread(office, ypos, xpos, i, -1);
            spread(office, ypos, xpos, 2+i, -1);
        }
    } else if(n == 3) {
        for(int i = 0; i < 4; ++i) {
            spread(office, ypos, xpos, i, 1);
            spread(office, ypos, xpos, i+1, 1);
            ret = min(ret, solve(office, pos+1));
            spread(office, ypos, xpos, i, -1);
            spread(office, ypos, xpos, i+1, -1);
        }
    } else if(n == 4) {
        for(int i = 0; i < 4; ++i) {
            spread(office, ypos, xpos, i, 1);
            spread(office, ypos, xpos, i+1, 1);
            spread(office, ypos, xpos, i+2, 1);
            ret = min(ret, solve(office, pos+1));
            spread(office, ypos, xpos, i, -1);
            spread(office, ypos, xpos, i+1, -1);
            spread(office, ypos, xpos, i+2, -1);
        }
    } else {
        for(int i = 0; i < 4; ++i) {
            spread(office, ypos, xpos, i, 1);
        }
        ret = min(ret, solve(office, pos+1));
        for(int i = 0; i < 4; ++i) {
            spread(office, ypos, xpos, i, -1);
        }
    }
    return ret;
}

int main() {
    cin >> col >> row;
    vector<vector<int> > office(col, vector<int>(row, 0));
    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            cin >> office[i][j];
            if(office[i][j] != 0) {
                if(office[i][j] == 6) {
                    office[i][j] = wall;
                    walls.push_back(make_pair(i, j));
                } else {
                    cctvs.push_back(make_pair(make_pair(i, j), office[i][j]));
                }
            }
        }
    }
    cctvCnt = cctvs.size();
    cout << solve(office, 0) << "\n";
}
