#include <bits/stdc++.h>
using namespace std;
int N;
struct Info {
    int start;
    int end;
    bool operator<(const Info& rhs) const {
        if(start == rhs.start) {
            return end < rhs.end;
        }
        return start < rhs.start;
    }
};
vector<Info> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        V[i] = { a, b };
    } 
    sort(V.begin(), V.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < N; i++) {
        int cur_start = V[i].start, cur_end = V[i].end;
        while(!pq.empty()) {
            int qtop = pq.top(); 
            if(qtop <= cur_start) pq.pop();
            else break;
        }
        pq.push(V[i].end);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << "\n";
}