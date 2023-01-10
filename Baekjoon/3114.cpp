#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int dx[] = {1, 0};
int dy[] = {0, 1};

int ddx[] = {1, -1};
int ddy[] = {-1, 1};

int R, C;
int cache[1501][1501];
vector<vector<string> > boards;
int A[1501][1501];
int ApSum[1501][1501];
int B[1501][1501];
int BpSum[1501][1501];

bool inRange(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}

void calculatePsum() {
    for(int i = 0; i < R; i++) {
        int y = i, x = 0;
        if(x == 0) {
            ApSum[y][x] = A[y][x];
            BpSum[y][x] = B[y][x];
        }
        int ny = y, nx = x;
        while(1) {
            int nny = ny + ddy[0], nnx = nx + ddx[0];
            if(!inRange(nny, nnx)) break;;
            ApSum[nny][nnx] = ApSum[ny][nx] + A[nny][nnx];
            BpSum[nny][nnx] = BpSum[ny][nx] + B[nny][nnx];
            ny = nny; nx = nnx;
        }
    }
    int y = R-1;
    for(int j = 1; j < C; j++) {
        int x = j;
        if(x == j) {
            ApSum[y][x] = A[y][x];
            BpSum[y][x] = B[y][x];
        }
        int ny = y, nx = x;
        while(1) {
            int nny = ny + ddy[0], nnx = nx + ddx[0];
            if(!inRange(nny, nnx)) break;;
            ApSum[nny][nnx] = ApSum[ny][nx] + A[nny][nnx];
            BpSum[nny][nnx] = BpSum[ny][nx] + B[nny][nnx];
            ny = nny; nx = nnx;
        }
    }

}

pii getEndPoint(pii p, int up) {
    int y = p.first, x = p.second;
    if(up) {
        if(x + y < C) {
            return pii(0, x+y);
        } else {
            int move = C - 1 - x;
            return pii(y-move, x+move);
        }
    } else {
        if(x + y < R) {
            return pii(x+y, 0);
        } else {
            int move = R - 1 - y;
            return pii(y+move, x-move);
        }
    }
}

int solve(int y, int x) {
    if(y == R-1 && x == C-1) return 0;
    if(y >= R || x >= C) return -1e9;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    int tmp = 0;
    for(int i = 0; i < 2; i++) {
        tmp = 0;
        int ny = y + dy[i], nx = x + dx[i];
        if(!inRange(ny, nx)) continue;
        pii ep = getEndPoint(pii(ny, nx), 1);
        int epy = ep.first, epx = ep.second;
        tmp += BpSum[epy][epx] - BpSum[ny][nx];
        tmp += ApSum[ny][nx] - A[ny][nx];

        ret = max(ret, tmp + solve(ny, nx));
    }
    tmp = 0;
    int ny = y, nx = x + 1;
    if(!inRange(ny, nx)) return ret;
    pii ep = getEndPoint(pii(ny, nx), 1);
    int epy = ep.first, epx = ep.second;
    tmp += BpSum[epy][epx] - BpSum[ny][nx] + B[ny][nx];
    tmp += ApSum[ny][nx] - A[ny][nx];

    ny = ny + 1;
    if(!inRange(ny, nx)) return ret;
    ep = getEndPoint(pii(ny, nx), 1);
    epy = ep.first, epx = ep.second;
    tmp += BpSum[epy][epx] - BpSum[ny][nx];
    tmp += ApSum[ny][nx] - A[ny][nx];
    return ret = max(ret, tmp + solve(ny, nx));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        boards.push_back(vector<string>());
        for(int j = 0; j < C; j++) {
            string str; cin >> str;
            if(str[0] == 'A') {
                A[i][j] = stoi(str.substr(1));
            } else if(str[0] == 'B') {
                B[i][j] = stoi(str.substr(1));
            }
            boards[i].push_back(str);
        }
    }
    calculatePsum();
    cout << solve(0, 0) << "\n";
}