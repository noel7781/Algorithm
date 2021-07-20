#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int l;
int dY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int visit[301][301];

int solve() {
    int now_y, now_x; cin >> now_y >> now_x;
    int tar_y, tar_x; cin >> tar_y >> tar_x;
    queue<tiii> q;
    q.push(make_tuple(now_y, now_x, 0));
    visit[now_y][now_x] = true;
    int ret = 0;
    while(!q.empty()) {
        tiii front = q.front();
        q.pop();
        int now_y = get<0>(front), now_x = get<1>(front), count = get<2>(front);
//        printf("Y : %d X :%d count %d\n", now_y, now_x, count);
        if(now_y == tar_y && now_x == tar_x) {
            return count;
        }
        for(int i = 0; i < 8; ++i) {
            int next_y = now_y + dY[i], next_x = now_x + dX[i];
            if(next_y < 0 || next_x < 0 || next_y >= l || next_x >= l)
                continue;
            if(visit[next_y][next_x]) {
                continue;
            }
            visit[next_y][next_x] = true;
            q.push(make_tuple(next_y, next_x, count+1));
        }
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        memset(visit, false, sizeof(visit));
        cin >> l;
        cout << solve() << "\n";
    }
}
