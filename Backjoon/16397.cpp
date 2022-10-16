#include <bits/stdc++.h>
using namespace std;
int N, T, G;
int dists[100000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T >> G;
    memset(dists, 0x3f, sizeof(dists));
    dists[N] = 0;
    queue<int> q;
    q.push(N);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(dists[now] > T) continue;
        int next = now + 1;
        if(next <= 99999 && dists[next] > dists[now]+1) {
            dists[next] = dists[now] + 1;
            q.push(next);
        }
        next = now * 2;
        if(next != 0) {
            if(next > 99999) continue;
            string tmp = to_string(next);
            tmp[0] -= 1;
            next = stoi(tmp);
        }
        if(next <= 99999 && dists[next] > dists[now]+1) {
            dists[next] = dists[now] + 1;
            q.push(next);
        }
    }
    if(dists[G] <= T) {
        cout << dists[G] << "\n";
    } else {
        cout << "ANG\n";
    }

}