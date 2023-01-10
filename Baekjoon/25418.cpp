#include <bits/stdc++.h>
using namespace std;
int A, K;
map<int, int> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> K;
    queue<int> q;
    q.push(A);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now == K) {
            cout << m[now] << "\n";
            return 0;
        }
        int cost = m[now];
        if(now+1 <= K && m[now+1] == 0) {
            m[now+1] = cost+1;
            q.push(now+1);
        }
        if(now*2 <= K && m[now*2] == 0) {
            m[now*2] = cost+1;
            q.push(now*2);
        }

    }
}