#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

// < cnt , dist , src , team >
typedef tuple<int, int, int, int> T;

int N, M;
int dist[1001][1001];
bool is_visit[1001][1001];
vector<int> teams;
int result_cnt = -1;
int result_pass = 1e9;

void solve() {
    priority_queue<T, vector<T>, greater<T> > pq;
    T start = make_tuple(0, 0, 0, teams[0]);
    pq.push(start);
    while(!pq.empty()) {
        T now = pq.top();
        pq.pop();
        int cnt = get<0>(now), pass = get<1>(now), src = get<2>(now), team = get<3>(now);
        if(src == M) {
            if(result_cnt == -1) {
                result_cnt = cnt;
                result_pass = pass;
                break;
            }
        }
        for(int i = 0; i < N; ++i) {
            if(!is_visit[src][i] && dist[src][i]) {
                is_visit[src][i] = true;
                if(teams[src] == teams[i]) {
                    pq.push(make_tuple(cnt, pass+dist[src][i], i, teams[i]));
                } else {
                    pq.push(make_tuple(cnt+1, pass+dist[src][i], i, teams[i]));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, 0, sizeof(dist));
    memset(is_visit, 0, sizeof(is_visit));
    cin >> N >> M;
    teams.assign(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> teams[i];
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }
    solve();
    cout << result_cnt << " " << result_pass << "\n";
}
