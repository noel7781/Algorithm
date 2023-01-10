#include <bits/stdc++.h>
using namespace std;
int N, H, T;
int h;
int change(int u) {
    if(u == 1) return u;
    return u / 2;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> H >> T;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++) {
        cin >> h; pq.push(h);
    }
    bool is_done = false;
    int cnt = 0;
    for(int i = 0; i < T; i++) {
        int top = pq.top(); pq.pop();
        if(top < H) {
            break;
        }
        top = change(top);
        pq.push(top);
        cnt++;
    }

    if(pq.top() < H) {
        is_done = true;
    }

    if(is_done) {
        cout << "YES\n";
        cout << cnt << "\n";
    } else {
        cout << "NO\n";
        cout << pq.top() << "\n";
    }
}