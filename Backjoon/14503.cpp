#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dX[4] = {0, 1, 0, -1};
int dY[4] = {-1, 0, 1, 0};
int room[51][51];
int n, m, r, c, d;

void printBoard() {
    cout<<"----------------------------------------\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0;j  < m; ++j) {
            cout<< room[i][j] << " ";
        }
        cout << endl;
    }
}

int solve() {
    int ret = 0;
    pii start = make_pair(r, c);
    queue<pair<pii, int> > q;
    q.push(make_pair(start, d));
    while(!q.empty()) {
        pair<pii, int> cur_state = q.front();
        q.pop();
        pii here = cur_state.first; int direction = cur_state.second;
        int hereY = here.first, hereX = here.second;
        //printBoard();
        //printf("now Y: %d now X: %d Direction %d\n", hereY, hereX, direction);
        if(room[hereY][hereX] == 0) {
            room[hereY][hereX] = 1;

            room[hereY][hereX] = ret+10;
            ret += 1;
        } 
        int end = 0;
        for(int cnt = 1; cnt <= 4; ++cnt) {
            int nextD = (direction - cnt + 4) % 4;
            int nextY = hereY + dY[nextD], nextX = hereX + dX[nextD];
            //printf("next Y: %d next X: %d next Direction %d\n", nextY, nextX, nextD);
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m || room[nextY][nextX] != 0) {
                end += 1;
            } else {
                q.push(make_pair(make_pair(nextY, nextX), nextD));
                break;
            }
        }
        if(end == 4) {
            int nextD = direction;
            int nextY = hereY + dY[(direction+2)%4], nextX = hereX + dX[(direction+2)%4];
            if(!(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m || room[nextY][nextX] == 1)) {
                q.push(make_pair(make_pair(nextY, nextX), nextD));
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }
    cout << solve() << "\n";
}
