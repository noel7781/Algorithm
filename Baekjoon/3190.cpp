#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;
int n;
int k, l;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};

void printBoard(vector<vector<int> > board, vector<pii> bodys) {
    for(int i= 0; i <bodys.size(); ++i) {
        board[bodys[i].first][bodys[i].second] = 2;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0;j < n;++j) {
            cout << board[i][j];
        }
        cout<<endl;
    }
}
void printBody(vector<pii> v) {
    cout << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << it->first << " " << it->second << " || ";
    }
    cout << "]\n";
}

int solve(vector<vector<int> > board, vector<pic>& rots) {
    int ret = 0;
    vector<pii> bodys;
    bodys.push_back(make_pair(0, 0));
    int d = 0;
    while(1) {
        int hereX = bodys.back().second, hereY = bodys.back().first;
        //printBoard(board,bodys);

        //printBody(bodys);
        int nextTime = rots.empty() ? 1e9 : rots.front().first;
        if(ret < nextTime) {
            int nextX = hereX + dX[d], nextY = hereY + dY[d]; 
            if(nextX >= n || nextY >= n || nextX < 0 || nextY < 0) return ret+1;
            for(int i = 0; i < bodys.size()-1; ++i) {
                if(bodys[i].first == nextY && bodys[i].second == nextX) return ret+1;
            }
            if(board[nextY][nextX] != 1) {
                bodys.erase(bodys.begin());
            }
            board[nextY][nextX] = 0;
            bodys.push_back(make_pair(nextY, nextX));
        } else {
            char dir = rots.front().second;
            if(dir == 'D') {
                d += 1;
                d %= 4;
            } else if(dir == 'L') {
                d += 3;
                d %= 4;
            }
            rots.erase(rots.begin());
            int nextX = hereX + dX[d], nextY = hereY + dY[d]; 
            if(nextX >= n || nextY >= n || nextX < 0 || nextY < 0) return ret+1;
            for(int i = 0; i < bodys.size()-1; ++i) {
                if(bodys[i].first == nextY && bodys[i].second == nextX) return ret+1;
            }
            if(board[nextY][nextX] != 1) {
                bodys.erase(bodys.begin());
            }
            board[nextY][nextX] = 0;
            bodys.push_back(make_pair(nextY, nextX));
        }
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<vector<int> > board(n, vector<int>(n, 0));
    cin >> k;
    for(int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        board[a-1][b-1] = 1;
    }
    cin >> l;
    vector<pic> rots(l);
    for(auto &x: rots) {
        cin >> x.first >> x.second;
    }
    cout << solve(board, rots) << "\n";
}
