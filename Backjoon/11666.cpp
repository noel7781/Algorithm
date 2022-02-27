#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int ans = 0;
    V.resize(N);
    for(auto &it: V) cin >> it.first >> it.second;
    sort(V.begin(), V.end());
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < N; i++) {
        int start_time = V[i].first, end_time = V[i].first + V[i].second;
        if(pq.empty()) {
            pq.push(end_time);
            ans += 1;
        } else {
            int top = pq.top();
            if(start_time < top) {
                pq.push(end_time);
                ans += 1;
            } else {
                while(!pq.empty() && start_time > pq.top()+M) {
                    pq.pop();
                }
                if(pq.empty()) {
                    pq.push(end_time);
                    ans += 1;
                } else {
                    pq.pop();
                    pq.push(end_time);
                }
            }
        }

    }
    cout << N - ans << "\n";
}