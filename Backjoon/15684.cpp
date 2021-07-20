#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
typedef pair<int, int> pii;

int n, m, h;

void printLadder(vector<vector<int> >& ladders) {
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n-1; ++j) {
            printf("ladders[%d][%d] : %d\n", i, j, ladders[i][j]);
        }
    }
}
int move(vector<vector<int> >& ladders, int row, int col) {
    if(row == h) {
        return col;
    }
    if(col < n-1 && ladders[row][col] == 1) {
        return move(ladders, row+1, col+1);
    } else if (col > 0 && ladders[row][col-1] == 1) {
        return move(ladders, row+1, col-1);
    } else {
        return move(ladders, row+1, col);
    }
}

bool check(vector<vector<int> >& ladders, pii info) {
    int row = info.first, col = info.second;
    if(ladders[row][col] == 1) return false;
    if(col == 0) {
        if(ladders[row][col+1] == 0) return true;
        return false;
    } else if(col > 0 && col < n-2) {
        if(ladders[row][col-1] == 0 && ladders[row][col+1] == 0) return true;
        return false;
    } else {
        if(ladders[row][col-1] == 0) return true;
        return false;
    }
}

void getPair(vector<vector<int> >& ladders, vector<pii>& pairs) {
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n-1; ++j) {
            pii now = make_pair(i, j);
            if(check(ladders, now)) {
                pairs.push_back(now);
            }
        }
    }
}

bool addLadder(vector<vector<int> >& ladders, vector<pii>& pairs, int adder, int pos) {
    if(adder == 0) {
        for(int i = 0; i < n; ++i) {
            if(move(ladders, 0, i) != i) {
                return false;
            }
        }
        return true;
    }
    for(int i = pos+1; i < pairs.size(); ++i) {
        if(check(ladders, pairs[i])) {
            int row = pairs[i].first, col = pairs[i].second;
            ladders[row][col] = 1;
            if(addLadder(ladders, pairs, adder-1, i)) {
                return true;
            }
            ladders[row][col] = 0;
        }
    }
    return false;
}

int solve(vector<vector<int> >& ladders) {
    int ret = -1;
    vector<pii> pairs;
    getPair(ladders, pairs);
    for(int adder = 0; adder <= 3; ++adder) {
        if(addLadder(ladders, pairs, adder, -1)) {
            return adder;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;
    vector<vector<int> > ladders(h, vector<int>(n-1, 0));
    for(int i = 0; i < m; ++i) {
        int pos, start; cin >> pos >> start;
        ladders[pos-1][start-1] = 1;
    }
    cout << solve(ladders) << "\n";
}
