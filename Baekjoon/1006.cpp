#include <bits/stdc++.h>
using namespace std;
int T, N, W;
vector<int> counts;

int solve(int index, vector<int>& visited) {
    if(index == N*2) return 0;
    int ret = 1e9;
    int floor = index / N;
    int left = (index-1+N) % N + (floor ? N : 0);
    int right = (index+1) % N + (floor ? N : 0);
    int near = index % N + (!floor ? N : 0);
    if(visited[index]) {
        return solve(index+1, visited);
    }
    visited[index] = 1;
    if(!visited[left] && counts[index] + counts[left] <= W) {
        visited[left] = 1;
        ret = min(ret, 1 + solve(index+1, visited));
        visited[left] = 0;
    }
    if(!visited[right] && counts[index] + counts[right] <= W) {
        visited[right] = 1;
        ret = min(ret, 1 + solve(index+1, visited));
        visited[right] = 0;
    }
    if(!visited[near] && counts[index] + counts[near] <= W) {
        visited[near] = 1;
        ret = min(ret, 1 + solve(index+1,  visited));
        visited[near] = 0;
    }
    ret = min(ret, 1 + solve(index+1, visited));
    visited[index] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> W;
        counts.resize(N * 2, 0);
        for(int i = 0; i < N * 2; i++) {
            cin >> counts[i];
        }
        vector<int> visited(N*2, 0);
        cout << solve(0, visited) << "\n";
    }
}