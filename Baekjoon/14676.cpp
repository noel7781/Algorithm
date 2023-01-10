#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> ins;
vector<vector<int> > adj;
vector<int> counts;
int X, Y;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    ins.resize(N+1);
    adj.resize(N+1);
    counts.resize(N+1);
    for(int i = 0; i < M; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y);
        ins[Y]++;
    }
    bool is_good = true;
    for(int i = 0; i < K; i++) {
        cin >> X >> Y;
        if(!is_good) continue;
        if(X == 1) {
            if(ins[Y] > 0) {
                is_good = false;
                continue;
            }
            counts[Y]++;
            for(const auto& next: adj[Y]) {
                if(counts[Y] == 1) ins[next]--;
            }
        } else {
            if(counts[Y] == 0) {
                is_good = false;
                break;
            }
            counts[Y]--;
            for(const auto& next: adj[Y]) {
                if(counts[Y] == 0) ins[next]++;
            }
        }
    }
    cout << (is_good ? "King-God-Emperor\n" : "Lier!\n");
}