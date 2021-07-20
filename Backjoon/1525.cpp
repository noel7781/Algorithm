#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

//typedef pair<pair<int, vector<vector<int> > >, pair<int, int> > complex;
typedef pair<pair<int, int  >, pair<int, int> > complex;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int> > board;

int getState(vector<vector<int> >& board) {
    int ret = 0;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[i][j]) ret += (board[i][j]) * pow(10, 3*i + j);
        }
    }
    return ret;
}

int solve(int y, int x) {

    int ret = -1;
    priority_queue<complex, vector<complex>, greater<complex> > pq;
    map<int, bool> m;
    pq.push(make_pair(make_pair(0, getState(board)), make_pair(y, x)));
    while(!pq.empty()) {
        int cnt = pq.top().first.first;
        int board_state = pq.top().first.second;
        vector<vector<int> > curr_board(3, vector<int>(3, 0));
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                //curr_board[i][j] = pq.top().first.second[i][j];
                curr_board[i][j] = board_state % 10;
                board_state /= 10;
            }
        }
        int now_y = pq.top().second.first;
        int now_x = pq.top().second.second;
        pq.pop();
        int state = getState(curr_board);
        if(m[state] == true) {
            continue;
        }
        m[state] = true;
        /*
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j) {
                cout << curr_board[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"now_y : "<< now_y << " and now_x : " << now_x << " cnt: " << cnt <<endl;
        cout<<"state: "<<state<<endl;
        cout<<"-------------------\n";
        */
        if(state == 87654321) return cnt;
        for(int i = 0; i < 4; ++i) {
            int next_y = now_y + dy[i], next_x = now_x + dx[i];
            if(next_y < 0 || next_x < 0 || next_y >= 3 || next_x >= 3) continue;
            else  {
                swap(curr_board[now_y][now_x], curr_board[next_y][next_x]);
                //pq.push(make_pair(make_pair(cnt+1, curr_board), make_pair(next_y, next_x)));
                pq.push(make_pair(make_pair(cnt+1, getState(curr_board)), make_pair(next_y, next_x)));
                swap(curr_board[now_y][now_x], curr_board[next_y][next_x]);
            }
        }
    }

    return ret;
}

int main() {
    board.assign(3, vector<int>(3, 0));
    int src_y = -1, src_x = -1;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                src_y = i;
                src_x = j;
            }
        }
    }
    cout << solve(src_y, src_x) << "\n";
}
