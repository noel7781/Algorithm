#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > clocks;
int east_side[4] = {2, 2, 2, 2};
int k;

void rotate(int clockN, int dir, vector<bool>& visit) {
    if(clockN < 0 || clockN >= 4) return;
    if(visit[clockN]) return;
    visit[clockN] = 1;
    int cur_west = (east_side[clockN] + 4) % 8;
    if(clockN > 0 && clocks[clockN-1][east_side[clockN-1]] != clocks[clockN][cur_west])  {
        rotate(clockN-1, -dir, visit);
    }
    if(clockN < 3 && clocks[clockN][east_side[clockN]] != clocks[clockN+1][(east_side[clockN+1]+4)%8]) {
        int right = (east_side[clockN+1] +4) % 8;
        rotate(clockN+1, -dir, visit);
    }
    east_side[clockN] = (((east_side[clockN] - dir) + 8 ) % 8);
    return;
}

int main() {
    clocks.assign(4, vector<int>(8, 0));
    vector<string> tmp = vector<string>(4);
    for(int i = 0; i < 4; ++i) {
        cin >> tmp[i];
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0;  j < 8; ++j) {
            clocks[i][j] = tmp[i][j] - 48;
        }
    }
    cin >> k;
    while(k--) {
        vector<bool> visit(4, 0);
        int n, d; cin >> n >> d;
        rotate(n-1, d, visit);
    }
    int ret = 0;
    for(int i = 0; i < 4; ++i) {
        if(clocks[i][(east_side[i]+6)%8])
            ret += (1 << i);
    }
    cout << ret << "\n";
}
