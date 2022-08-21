#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    priority_queue<int> pq;
    cin >> N;
    int ds; cin >> ds;
    for(int j = 0; j < N-1; j++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while(!pq.empty()) {
        int top = pq.top(); pq.pop();
        if(ds > top) {
            cout << ans << "\n";
            return 0;
        }
        ans++;
        ds++;
        pq.push(top-1);
    }
    cout << 0 << "\n";
}