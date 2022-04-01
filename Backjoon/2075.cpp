#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> board[i][j];
    priority_queue<tiii> pq;
    for(int j = 0; j < N; j++) pq.push({board[N-1][j], j, N-1});
    int popcount = 0;
    int ret = 0;
    while(true) {
        auto [popped, col, row] = pq.top(); pq.pop();
        ret = popped;
        popcount++;
        if(popcount == N) break;
        pq.push({board[row-1][col], col, row-1});
    }
    cout << ret << "\n";
}